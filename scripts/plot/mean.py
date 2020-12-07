import sys
import os
import pandas as pd
import matplotlib.pyplot as plt

csvFile = pd.read_csv(sys.argv[1])

p = csvFile['p'].to_numpy()
bch = csvFile['bru_mean'].to_numpy()
ktt = csvFile['ktt_mean'].to_numpy()
by_bef = csvFile['by_before_mean'].to_numpy()
by_aft = csvFile['by_after_mean'].to_numpy()
expcomp = csvFile['expcomp_mean'].to_numpy()
expsquares = csvFile['expsquares_mean'].to_numpy()
exp = csvFile['exp_mean'].to_numpy()

plt.plot(p, bch, label="BCH")
plt.plot(p, ktt, label="KTT")
plt.plot(p, by_bef, label="BY before")
plt.plot(p, by_aft, label="BY after")
plt.plot(p, expcomp, label="Fermat-comp")
plt.plot(p, expsquares, label="Fermat-sq")
plt.plot(p, exp, label="Fermat-tab")

plt.xlabel("p (bit)")
plt.ylabel("Time (cycles)")
plt.legend(loc=2)
plt.grid()
plt.yscale("log")
plt.show()



