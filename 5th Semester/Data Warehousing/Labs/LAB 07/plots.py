import matplotlib.pyplot as plt
import numpy as np

# Set dark/modern aesthetic style
plt.style.use('dark_background')
plt.rcParams['font.family'] = 'sans-serif'
plt.rcParams['font.size'] = 10

# Data Scales & Execution Times (in ms)
scales = ['1K', '10K', '100K', '1M']
scale_labels = [1000, 10000, 100000, 1000000]

# Execution times without indexes across scales (from your lab data)
q1_times = [1, 130, 349, 2569]
q2_times = [18, 36, 517, 744]
q3_times = [0, 0, 0, 0]
q4_times = [5, 6, 3, 3]
q5_times = [4, 42, 292, 1874]

# -----------------------------------------------------------------------------
# GRAPH 1: Execution Time vs. Data Scale (Un-indexed Baseline)
# -----------------------------------------------------------------------------
plt.figure(figsize=(10, 6))

plt.plot(
    scales, q1_times, marker='o', linewidth=2.5, label='Query 1 (Simple Filter)'
)
plt.plot(
    scales,
    q2_times,
    marker='s',
    linewidth=2.5,
    label='Query 2 (Simple Join & Filter)',
)
plt.plot(
    scales,
    q3_times,
    marker='^',
    linewidth=2.5,
    label='Query 3 (Multi-Join Text Search)',
)
plt.plot(
    scales, q4_times, marker='d', linewidth=2.5, label='Query 4 (Join & Group By)'
)
plt.plot(
    scales,
    q5_times,
    marker='x',
    linewidth=2.5,
    label='Query 5 (Complex Join & Agg)',
)

plt.title(
    'Graph 1: Query Execution Time vs. Data Scale (Un-indexed)',
    fontsize=14,
    pad=15,
    fontweight='bold',
)
plt.xlabel('Data Scale (Number of Students)', fontsize=11, labelpad=10)
plt.ylabel('Elapsed Execution Time (ms)', fontsize=11, labelpad=10)
plt.grid(True, linestyle='--', alpha=0.3)
plt.legend(loc='upper left', frameon=True, facecolor='#222222', edgecolor='none')
plt.tight_layout()
plt.savefig('graph1_execution_time_vs_scale.png', dpi=300)
plt.show()

# -----------------------------------------------------------------------------
# GRAPH 2: Before vs. After Indexing at 1 Million Scale
# -----------------------------------------------------------------------------
queries = ['Q1', 'Q2', 'Q3', 'Q4', 'Q5']
before_indexing = [2569, 744, 0, 3, 1874]
after_indexing = [2314, 1265, 0, 1, 1114]

x = np.arange(len(queries))
width = 0.35

plt.figure(figsize=(10, 6))

rects1 = plt.bar(
    x - width / 2,
    before_indexing,
    width,
    label='Before Indexing',
    color='#e74c3c',
)
rects2 = plt.bar(
    x + width / 2,
    after_indexing,
    width,
    label='After Indexing',
    color='#2ecc71',
)

plt.title(
    'Graph 2: Query Execution Time at 1M Scale (Before vs. After Indexing)',
    fontsize=14,
    pad=15,
    fontweight='bold',
)
plt.xlabel('Query Type', fontsize=11, labelpad=10)
plt.ylabel('Elapsed Execution Time (ms)', fontsize=11, labelpad=10)
plt.xticks(x, queries)
plt.grid(axis='y', linestyle='--', alpha=0.3)
plt.legend(loc='upper right', frameon=True, facecolor='#222222', edgecolor='none')

# Add data values on top of bars
for rect in rects1:
  height = rect.get_height()
  if height > 0:
    plt.annotate(
        f'{height}ms',
        xy=(rect.get_x() + rect.get_width() / 2, height),
        xytext=(0, 3),
        textcoords='offset points',
        ha='center',
        va='bottom',
        fontsize=8,
    )

for rect in rects2:
  height = rect.get_height()
  if height > 0:
    plt.annotate(
        f'{height}ms',
        xy=(rect.get_x() + rect.get_width() / 2, height),
        xytext=(0, 3),
        textcoords='offset points',
        ha='center',
        va='bottom',
        fontsize=8,
    )

plt.tight_layout()
plt.savefig('graph2_before_vs_after_indexing.png', dpi=300)
plt.show()