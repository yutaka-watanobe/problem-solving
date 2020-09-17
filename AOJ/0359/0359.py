D = ["thu", "fri", "sat", "sun", "mon", "tue", "wed"] # 曜日を表す配列
X = int(input())
print(D[X % 7]) # 7で割った余りから曜日を求めてその文字列を出力
