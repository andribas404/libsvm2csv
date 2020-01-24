/*

Copyright 2019 Andrey Petukhov

*/

#include <algorithm>
#include <cstdio>
#include <string>
#include <tuple>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using std::string;
using std::vector;

using mymap = std::unordered_map<string, size_t>;
using mytuple = std::tuple<string, string>;

const size_t MAX_SIZE = 100;

class Converter {
 public:
    Converter(FILE* fin, FILE* fout);
    ~Converter() {}
    void convert();

 private:
    string itoa(size_t n);
    vector<string> get_features();
    void map_features();
    vector<mytuple> parse_line(const string& s);
    string map_line(const vector<mytuple>& parsed, size_t line_index);
    string join(
        const vector<string>& v,
        const string& delimiter,
        const string& end);

    FILE* fin;
    FILE* fout;
    mymap features;
};

void convert(FILE *fin, FILE *fout) {
    Converter c(fin, fout);
    c.convert();
}

Converter::Converter(FILE* fin, FILE* fout) :
    fin(fin),
    fout(fout) {}

string Converter::itoa(size_t n) {
    char buf[MAX_SIZE];
    snprintf(buf, MAX_SIZE, "%ld", n);
    string s(buf);
    return s;
}

void Converter::convert() {
    vector<string> header = get_features();
    string joined = join(header, ",", "\n");

    rewind(fin);

    fputs(joined.c_str(), fout);

    map_features();
}

vector<string> Converter::get_features() {
    string s;
    std::unordered_set<string> keys;
    string terminal = "\r#\n";
    bool skip = false;

    for (;;) {
        int c = fgetc(fin);
        if (c == EOF) {
            break;
        }
        if (skip) {
            if (c == '\n') {
                skip = false;
            }
            continue;
        }
        if (terminal.find(c) != string::npos) {
            s.push_back(' ');
            vector<mytuple> parsed = parse_line(s);
            // +2 = skip target, qid
            for (auto it = parsed.cbegin() + 2; it < parsed.cend(); it++) {
                auto[s1, s2] = *it;
                keys.emplace(s1);
            }
            s.clear();
            if (c != '\n') {
                skip = true;
            }
        } else {
            s.push_back(c);
        }
    }
    // convert string to number and sort features
    vector<int> tmp;
    for (auto it = keys.cbegin(); it != keys.cend(); it++) {
        tmp.emplace_back(atoi(it->c_str()));
    }
    std::sort(tmp.begin(), tmp.end());
    // 0 - index
    features["target"] = 1;
    features["qid"] = 2;
    vector<string> header { "index", "target", "qid" };
    size_t pos = 3;
    for (auto it = tmp.begin(); it != tmp.end(); it++) {
        string key = itoa(*it);
        header.emplace_back(key);
        features[key] = pos++;
    }
    return header;
}

void Converter::map_features() {
    string s;
    size_t line_index = 0;
    string terminal = "\r\n#";
    bool skip = false;

    for (;;) {
        int c = fgetc(fin);
        if (c == EOF) {
            break;
        }
        if (skip) {
            if (c == '\n') {
                skip = false;
            }
            continue;
        }
        if (terminal.find(c) != string::npos) {
            s.push_back(' ');
            vector<mytuple> parsed = parse_line(s);
            string buf = map_line(parsed, line_index++);
            fputs(buf.c_str(), fout);
            s.clear();
            if (c != '\n') {
                skip = true;
            }
        } else {
            s.push_back(c);
        }
    }
}

vector<mytuple> Converter::parse_line(const string& s) {
    vector<mytuple> row;
    size_t left = 0;
    int middle = -1;
    size_t right = 0;
    for (size_t i = 0; i < s.size(); i++) {
        switch (s[i]) {
            case ' ':
            case '\t':
                if (right > left) {
                    string s1 = "";
                    string s2 = "";
                    if (middle != -1) {
                        s1 = s.substr(left, middle - left);
                        s2 = s.substr(middle + 1, right - middle - 1);
                    } else {
                        s1 = "target";
                        s2 = s.substr(left, right - left);
                    }
                    auto t = std::make_tuple(s1, s2);
                    row.emplace_back(t);
                }
                left = right = i + 1;
                middle = -1;
                break;
            case ':':
                middle = i;
                right++;
                break;
            default:
                right++;
                break;
        }
    }
    return row;
}

string Converter::map_line(const vector<mytuple>& parsed, size_t line_index) {
    vector<string> v(features.size() + 1, "0");
    v[0] = itoa(line_index);
    // target
    for (auto[feature, value] : parsed) {
        size_t pos = features[feature];
        v[pos] = value;
    }
    string joined = join(v, ",", "\n");
    return joined;
}

string Converter::join(
    const vector<string>& v,
    const string& delimiter,
    const string& end) {
    string joined(v[0]);
    for (size_t i = 1; i < v.size(); i++) {
        joined.append(delimiter);
        joined.append(v[i]);
    }
    joined.append(end);
    return joined;
}
