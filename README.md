# ArduinoMaster
## 簡介
ArduinoMaster 是一個以 OpenAI 的 GPT 為基礎，提供自動撰寫 Arduino 程式碼註解的工具。透過我們的工具，您將能快速理解 Arduino 程式碼的結構和功能，並且快速掌握 Arduino 的使用，是 Arduino 入門者的最佳助手。
### 大師講解前
![https://github.com/Oliver0804/GPT_ArduinoMaster/blob/main/%E6%88%AA%E5%9C%96%202023-06-21%20%E4%B8%8B%E5%8D%885.37.53.png](https://github.com/Oliver0804/GPT_ArduinoMaster/blob/main/%E6%88%AA%E5%9C%96%202023-06-21%20%E4%B8%8B%E5%8D%885.37.53.png)
### 大師講解後
![https://github.com/Oliver0804/GPT_ArduinoMaster/blob/main/%E6%88%AA%E5%9C%96%202023-06-21%20%E4%B8%8B%E5%8D%885.37.32.png](https://github.com/Oliver0804/GPT_ArduinoMaster/blob/main/%E6%88%AA%E5%9C%96%202023-06-21%20%E4%B8%8B%E5%8D%885.37.32.png)

### python代碼支持
![https://github.com/Oliver0804/GPT_ArduinoMaster/blob/main/%E6%88%AA%E5%9C%96%202023-06-21%20%E4%B8%8B%E5%8D%8810.45.09.png](https://github.com/Oliver0804/GPT_ArduinoMaster/blob/main/%E6%88%AA%E5%9C%96%202023-06-21%20%E4%B8%8B%E5%8D%8810.45.09.png)

## 開始使用
下面將逐步指導您如何安裝並使用 ArduinoMaster。

## 安裝步驟
### 克隆此 GitHub 儲存庫
```bash
git clone https://github.com/your_username/ArduinoMaster.git
```
### 移動到 ArduinoMaster 目錄
```bash
cd ArduinoMaster
```
建立新的 Conda 環境 (此處假設您已經安裝了 Conda)
```bash
conda create --n arduino_env python=3.11
```
啟動 Conda 環境
```bash
conda activate arduino_env
```
安裝 requirements.txt 中的必要 Python 套件
```bash
pip install -r requirements.txt
```
使用方式
在 Jupyter Notebook 中開啟 arduino_notebook.ipynb 檔案
```bash
jupyter notebook ArduinoMaster.ipynb 
```
在 notebook 中，輸入您的 Arduino 程式碼路徑


## 注意事項
配置檔案存放於.cfg中，請自行添加OPENAPI_KEY
