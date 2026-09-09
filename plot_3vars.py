"""

E. Wes Bethel, Copyright (C) 2022

October 2022

Description: This code loads a .csv file and creates a 3-variable plot

Inputs: the named file "sample_data_3vars.csv"

Outputs: displays a chart with matplotlib

Dependencies: matplotlib, pandas modules

Assumptions: developed and tested using Python version 3.8.8 on macOS 11.6

"""

import pandas as pd
import matplotlib.pyplot as plt


# fname = "sample_data_3vars.csv"
fname = "submit_data2.csv"
df = pd.read_csv(fname, comment="#")
print(df)

var_names = list(df.columns)

print("var names =", var_names)

# split the df into individual vars
# assumption: column order - 0=problem size, 1=blas time, 2=basic time

problem_sizes = df[var_names[0]].values.tolist()
code1_time = df[var_names[1]].values.tolist()
code2_time = df[var_names[2]].values.tolist()
code3_time = df[var_names[3]].values.tolist()

# Compute MFLOP/s from problem size (ops) and runtime (time)
code1_mflops = [
    (n / 1000000.0) / t if pd.notnull(t) and t > 0 else 0
    for n, t in zip(problem_sizes, code1_time)
]
code2_mflops = [
    (n / 1000000.0) / t if pd.notnull(t) and t > 0 else 0
    for n, t in zip(problem_sizes, code2_time)
]
code3_mflops = [
    (n / 1000000.0) / t if pd.notnull(t) and t > 0 else 0
    for n, t in zip(problem_sizes, code3_time)
]

plt.title("Memory Access Performance (MFLOP/s)")

xlocs = [i for i in range(len(problem_sizes))]

plt.xticks(xlocs, problem_sizes)

# Plot the computed MFLOP/s values rather than time
plt.plot(code1_mflops, "r-o")
plt.plot(code2_mflops, "b-x")
plt.plot(code3_mflops, "g-^")

# plt.xscale("log")
# plt.yscale("log")

plt.xlabel("Problem Sizes")
plt.ylabel("MFLOP/s")

varNames = [var_names[1], var_names[2], var_names[3]]
plt.legend(varNames, loc="best")

plt.grid(axis="both")

plt.show()

# EOF
