import random
import matplotlib.pyplot as plt

# モンテカルロ法で π を近似する関数
def monte_carlo_pi(num_samples):
    inside_circle = 0
    points = []

    for _ in range(num_samples):
        x = random.uniform(-1, 1)
        y = random.uniform(-1, 1)
        distance = x**2 + y**2
        if distance <= 1:
            inside_circle += 1
            points.append((x, y, 'b'))  # 円の内側の点（青）
        else:
            points.append((x, y, 'r'))  # 円の外側の点（赤）

    pi_estimate = (inside_circle / num_samples) * 4
    return pi_estimate, points

# サンプル数
num_samples = 10000

# π の近似値を求め、点を取得
pi_estimate, points = monte_carlo_pi(num_samples)

# 点をプロット
plt.figure(figsize=(8, 8))
for point in points:
    plt.plot(point[0], point[1], marker='o', color=point[2], markersize=1)

# 単位円をプロット
circle = plt.Circle((0, 0), 1, color='g', fill=False)
plt.gca().add_artist(circle)

# グラフの設定
plt.xlim(-1.1, 1.1)
plt.ylim(-1.1, 1.1)
plt.title(f'Monte Carlo Simulation for Pi\nEstimated Pi = {pi_estimate}')
plt.xlabel('x')
plt.ylabel('y')
plt.gca().set_aspect('equal', adjustable='box')
plt.grid(True)
plt.show()