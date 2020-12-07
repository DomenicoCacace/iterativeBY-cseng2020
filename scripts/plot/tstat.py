import sys
import os
import pandas as pd
import matplotlib.pyplot as plt

csvFile = pd.read_csv(sys.argv[1])

p = csvFile['p'].to_numpy()
bch = csvFile['bru_tstat'].to_numpy()
ktt = csvFile['ktt_tstat'].to_numpy()
by = csvFile['by_tstat'].to_numpy()
expcomp = csvFile['expcomp_tstat'].to_numpy()
expsquares = csvFile['expsquares_tstat'].to_numpy()
exp = csvFile['exp_tstat'].to_numpy()

limit = []

for i in range(p.size):
    bch[i] = abs(bch[i])
    ktt[i] = abs(ktt[i])
    by[i] = abs(by[i])
    expcomp[i] = abs(expcomp[i])
    expsquares[i] = abs(expsquares[i])
    exp[i] = abs(exp[i])
    limit.append(4.5)

plt.plot(p, bch, label="BCH")
plt.plot(p, ktt, label="KTT")
plt.plot(p, by, label="BY")
plt.plot(p, expcomp, label="Fermat-comp")
plt.plot(p, expsquares, label="Fermat-sq")
plt.plot(p, exp, label="Fermat-tab")
plt.plot(p, limit, linestyle="dashed")

plt.xlabel("p (bit)")
plt.ylabel("t statistic (abs. value)")
plt.legend(loc=2)
plt.grid()
plt.yscale("log")
plt.show()



