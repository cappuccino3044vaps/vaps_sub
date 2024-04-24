import pandas as pd
import random

def generate_data():
    data = [random.randint(1, 100) for _ in range(4)]
    df = pd.DataFrame(data, columns=['value'])
    max_value = df['value'].max()
    max_index = df['value'].idxmax()
    return max_value, max_index

