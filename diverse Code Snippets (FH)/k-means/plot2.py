import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
import os

# Before clustering
df = pd.read_csv("mall_data.csv", header=None)
df.columns = ["Annual income (k$)", "Spending Score (1-100)"]
sns.scatterplot(x=df["Annual income (k$)"], 
                y=df["Spending Score (1-100)"])
plt.title("Scatterplot of spending (y) vs income (x)")

# After clustering
plt.figure()
df = pd.read_csv("output.csv")
sns.scatterplot(x=df.x, y=df.y, 
                hue=df.c, 
                palette=sns.color_palette("hls", n_colors=5))
plt.xlabel("Annual income (k$)")
plt.ylabel("Spending Score (1-100)")
plt.title("Clustered: spending (y) vs income (x)")

# Check if clusters.csv exists
if os.path.exists("clusters.csv"):
    clusters = pd.read_csv("clusters.csv")
    plt.scatter(clusters.x, clusters.y, c='black', marker='X', s=100, label='Centroids')
    plt.legend()

plt.show()

