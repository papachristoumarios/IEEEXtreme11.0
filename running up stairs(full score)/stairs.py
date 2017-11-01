T = int(raw_input())
for t in range(T):
    val1 = 1
    val2 = 1;
    N = int(raw_input())
    for i in range(N - 1):
        val = val1 + val2
        val1 = val2
        val2 = val
    print val2
