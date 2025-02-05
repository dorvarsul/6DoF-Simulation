import pandas as pd
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Load trajectory data
df = pd.read_csv("trajectory.csv")

# Create plot
fig = plt.figure(figsize=(10,7))
ax = fig.add_subplot(111, projection='3d')

# plot trajectory
ax.plot(df['x'], df['y'], df['z'], label="Trajectory", color="r")

# labels
ax.set_xlabel("X (m)")
ax.set_ylabel("Y (m)")
ax.set_zlabel("Z (m)")
ax.set_title("Trajectory")
ax.legend()

# Show plot
plt.show()