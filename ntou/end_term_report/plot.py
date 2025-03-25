import matplotlib.pyplot as plt
import matplotlib.image as mpimg
# import easygui

PATH = ""

y = []
with open(PATH+"ANNSFM_outputs.txt", 'r') as f:
	for line in f.readlines():
		y.append(float(line.replace("\n","")))

x = range(708)
plt.plot(x,y)
plt.xlabel("data point")
plt.ylabel("storm suge (cm)")
plt.show()

# easygui.msgbox("執行已隨輸出圖表結束","成功")