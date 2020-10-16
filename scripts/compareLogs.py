import sys
import os
import pandas as pd
import plotly.express as px

logs = sys.argv

base_log = pd.read_csv(logs[1])
curr_log = pd.read_csv(logs[2])

mean_base = base_log['by_mean'].to_numpy()
mean_curr = curr_log['by_mean'].to_numpy()

mean_curr /= mean_base 
mean_curr -= 1
mean_curr *= -100

tot_mean = 0

for item in mean_curr:
    print("%.4f" % item)
    tot_mean+=item

tot_mean /= mean_curr.size
print("Global: %.4f" % tot_mean)

    
