# Cau 1
# Nguoi dung nhap so tien PV va lai suat interest_rate
PV = float(input("Nhap so tien muon gui (PV): "))
interest_rate = float(input("Nhap lai suat (interest_rate, dang thap phan, vi du: 0.025): "))

# Tinh so tien nhan duoc sau 1 nam
FV = PV * (1 + interest_rate)
print(f"So tien nhan duoc sau 1 nam la: {FV:.2f}")

# Cau 2
# Danh sach cac cong ty va gia tri
companies = ['FPT', 'SIS', 'VBC', 'VNM']
prices = [100, 30, 70, 120]

# Hien thi 3 cong ty dau va 3 cong ty cuoi
print("3 cong ty dau:", companies[:3])
print("3 cong ty cuoi:", companies[-3:])

# Tinh gia cua FPT
FPT_price = prices[0] * 100000
print(f"Gia cua FPT la: {FPT_price:,} VND")


# Cau 3
# Gia tri cho truoc
Rf = 0.02  # Loi suat phi rui ro
Rm = 0.05  # Loi suat thi truong
beta = 1.25  # He so beta

# Tinh loi suat ky vong
expected_return = Rf + beta * (Rm - Rf)
print(f"Loi suat ky vong theo mo hinh CAPM la: {expected_return:.2%}")

# Cau 4
# Danh sach co phieu, gia, va khoi luong
stocks = ['VNM', 'HPG', 'VCB', 'VIC', 'MBB']
prices = [70, 25, 60, 90, 25]  # Gia co phieu
quantities = [100, 900, 200, 400, 700]  # Khoi luong co phieu

# Tinh tong gia tri tung co phieu va tong danh muc
total_portfolio_value = 0
print("Tong gia tri cua tung co phieu:")
for stock, price, quantity in zip(stocks, prices, quantities):
    stock_value = price * quantity
    total_portfolio_value += stock_value
    print(f"{stock}: {stock_value:,} VND")

print(f"Tong gia tri danh muc: {total_portfolio_value:,} VND")


# Cau 1
stkA = [0.1, 0.2, 0.05, 0.4, -0.1, -0.05]

# Tim index ung voi loi suat lon nhat
max_value = stkA[0]
max_index = 0

for i in range(len(stkA)):
    if stkA[i] > max_value:
        max_value = stkA[i]
        max_index = i

print(f"Loi suat lon nhat la {max_value}, tai chi so (index): {max_index}")

# Cau 2
# Tinh tong loi suat
total = 0
for value in stkA:
    total += value

# Tinh loi suat trung binh
average = total / len(stkA)
print(f"Loi suat trung binh cua co phieu A la: {average:.2f}")

# Cau 3
import math

# Tinh do lech chuan
variance_sum = 0
for value in stkA:
    variance_sum += (value - average) ** 2

variance = variance_sum / len(stkA)
std_dev = math.sqrt(variance)

print(f"Do lech chuan cua loi suat co phieu A la: {std_dev:.2f}")

import math

# Loi suat cua co phieu A va B
stkA = [0.1, 0.2, 0.05, 0.4, -0.1, -0.05]
stkB = [0.03, 0.2, 0.3, -0.2, -0.05, 0.4]

# 1. Tinh loi suat trung binh
meanA = sum(stkA) / len(stkA)  # Loi suat trung binh co phieu A
meanB = sum(stkB) / len(stkB)  # Loi suat trung binh co phieu B

# 2. Tinh do lech chuan
# Su dung cong thuc do lech chuan sqrt(1/n * sum((x - mean)^2))
stdA = math.sqrt(sum((x - meanA) ** 2 for x in stkA) / len(stkA))  # Do lech chuan co phieu A
stdB = math.sqrt(sum((x - meanB) ** 2 for x in stkB) / len(stkB))  # Do lech chuan co phieu B

# 3. Tinh he so tuong quan
# Cong thuc: corr = covariance / (stdA * stdB)
covariance = sum((stkA[i] - meanA) * (stkB[i] - meanB) for i in range(len(stkA))) / len(stkA)  # Hiep phuong sai
correlation = covariance / (stdA * stdB)  # He so tuong quan

# Ket qua
print("Loi suat trung binh cua co phieu A:", meanA)
print("Loi suat trung binh cua co phieu B:", meanB)
print("Do lech chuan cua co phieu A:", stdA)
print("Do lech chuan cua co phieu B:", stdB)
print("He so tuong quan giua co phieu A va B:", correlation)