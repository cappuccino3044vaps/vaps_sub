import pandas as pd
import os

# テキストファイルを読み込み、CSVファイルに変換し、ソートしてヘッダーを追加する関数
def convert_and_sort_txt_to_csv(txt_file, csv_file):
    # テキストファイルを読み込み、データフレームに変換
    df = pd.read_csv(txt_file, sep='　', header=None, names=['社名', '車種名'])
    
    # 重複行を削除
    df = df.drop_duplicates()
    
    # 社名・車種名でソート
    df_sorted = df.sort_values(by=['社名','車種名'])
    
    # ソートされたデータをCSVファイルに書き込む
    df_sorted.to_csv(csv_file, index=False, encoding='utf-8')

# 実行部分
if __name__ == "__main__":
    # カレントディレクトリの絶対パスを取得
    current_dir = os.path.dirname(os.path.abspath(__file__))
    
    # ファイルの絶対パスを作成
    txt_file = os.path.join(current_dir, 'cars_memo.txt')
    csv_file = os.path.join(current_dir, 'sorted_cars_memo.csv')
    
    convert_and_sort_txt_to_csv(txt_file, csv_file)
    print(f"{txt_file} を {csv_file} に変換してソートし、重複行を削除してヘッダーを追加しました。")