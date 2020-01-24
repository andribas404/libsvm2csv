# libsvm2csv

## Installation

`pip install libsvm2csv`

### Convert LIBSVM format into CSV


```
from libsvm2csv import convert
convert("libsvm-data.txt", "data.csv")
```

`libsvm-data.txt`

```
1 qid:1 2:0.14  4:0.97  5:0.45
0 qid:1 1:0.15  3:0.75  2:0.24  4:0.6
2 qid:1 1:0.71  2:0.36  3:0.58  5:0.12
0 qid:2 4:0.79  3:0.01  2:0.05  5:0.27
3 qid:2 1:0.42  2:0.79  3:0.30  4:0.76
```

`data.csv`

```
index,target,qid,1,2,3,4,5
0,1,1,0,0.14,0,0.97,0.45
1,0,1,0.15,0.24,0.75,0.6,0
2,2,1,0.71,0.36,0.58,0,0.12
3,0,2,0,0.05,0.01,0.79,0.27
4,3,2,0.42,0.79,0.30,0.76,0
```