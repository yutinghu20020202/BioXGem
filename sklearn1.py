import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import math
from sklearn.preprocessing import StandardScaler

data = pd.read_csv('data.csv')  # 讀入csv檔，並把資料命名為 'data'
data.head(10) # show出前10筆資料
print(data.head(10))

# 觀察資料的統計資訊：觀察資料的統計資訊：age有缺失，Fare有人沒花錢搭船
data.describe()
print(data.describe())

# 知道891人中有多少人存活：value_counts()這列中這列中每個不同的值中多少個例子
data['Survived'].value_counts()

'''
# 可視化圖（長條圖）
sns.countplot(x='Survived', data=data)
# 可視化（圓餅圖）
colors = ["lightgreen", "red"]
fig, ax = plt.subplots(figsize=(5, 5), facecolor='white')
data["Survived"].value_counts().plot(
    kind="pie", #圖形類別: 圓餅圖
    shadow=True, #圓餅圖要不要有陰影
    startangle=90,#設定圓餅圖角度
    figsize=(5, 5),#設定圖形的大小
    autopct="%1.2f%%",
    colors=colors,
)
plt.title("Survived", fontsize=20, color="blue")
plt.show()
'''
'''
# 可視化'sex','pclass','sibsp','parch','embarked'長條圖
cols = ['Sex','Pclass','SibSp','Parch','Embarked']

n_rows = 2
n_cols = 3

# The subplot grid and figure size of each graph
fig, axs = plt.subplots(n_rows, n_cols, figsize=(n_cols * 3.2, n_rows * 3.2))

for r in range(n_rows):
    for c in range(n_cols):
        i = r * n_cols + c  # index to go through the number of columns
        if i < len(cols):
            ax = axs[r][c]  # show where to position each subplot
            sns.countplot(x=data[cols[i]], hue=data['Survived'], ax=ax)
            ax.set_title(cols[i])
            ax.legend(title='Survived', loc='upper right')

plt.tight_layout()
plt.show()
'''
#看缺失值:Age 、 Cabin 與 Embarked 三個欄位都有，而且cabin超多，所以直接把那行刪掉
print(data.isna().sum())

# 把沒有要分析的Cabin','Name','PassengerId'刪除
data = data.drop(['Cabin','Name','PassengerId'], axis=1)
data = data.drop(['Ticket'] , axis =1 )
# 把'Embarked','Age'有缺失值的列刪掉
data = data.dropna(subset =  ['Embarked','Age'])

# 看一下剩多少特徵幾筆資料
print(data.shape)

# 看一下data types: sex和embarked都不是數值，所以要處理這兩個
print(data.dtypes)

# 觀察sex, embarked有哪些字
print(data['Sex'].unique())
print(data['Embarked'].unique())

#用label encoder處理，類別 (categorical)或是文字(text)的資料轉換成數字
from sklearn.preprocessing import LabelEncoder
labelencoder = LabelEncoder()
# Encode the sex column
data.iloc[:, 2] = labelencoder.fit_transform(data.iloc[:, 2].values)
# Encode the embarked column
data.iloc[:, 7] = labelencoder.fit_transform(data.iloc[:, 7].values)

# 重複一下74行，確認字已經變數值
print(data['Sex'].unique())
print(data['Embarked'].unique())

# 重複一下71行，再看一下data types
print(data.dtypes)

# y設定自變量x（手中有的資料），設定自變量y（結果存活率）
X = data.iloc[:, 1:8].values
y = data.iloc[:, 0].values
# 把資料切成 80% 訓練集 ， 20% 測試集
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.2, random_state = 0)
# 標準化
#Scale the data 
from sklearn.preprocessing import StandardScaler
sc = StandardScaler()
X_trian = sc.fit_transform(X_train)
X_test = sc.transform(X_test)

# 建立七個 function with many mechaine learning models
def models(X_train, y_train):

    # Use Logistic Regression
    from sklearn.linear_model import LogisticRegression
    log = LogisticRegression(random_state = 0)
    log.fit(X_train, y_train)

    # Use KNeighbors 
    from sklearn.neighbors import KNeighborsClassifier
    knn = KNeighborsClassifier(n_neighbors= 5, metric = 'minkowski', p = 2)
    knn.fit(X_train, y_train)

    # Use SVC (linear kernal)
    from sklearn.svm import SVC
    svc_lin = SVC(kernel='linear', random_state = 0)
    svc_lin.fit(X_train,y_train)

    # Use SVC (RBF kernal)
    from sklearn.svm import SVC
    svc_rbf = SVC(kernel='rbf', random_state = 0)
    svc_rbf.fit(X_train,y_train)

    # Use GaussianNB 
    from sklearn.naive_bayes import GaussianNB
    gauss = GaussianNB()
    gauss.fit(X_train, y_train)

    # Use Dicision Tree
    from sklearn.tree import DecisionTreeClassifier
    tree = DecisionTreeClassifier(criterion = 'entropy', random_state = 0)
    tree.fit(X_train, y_train)

    # Use the RandomForestClassifier
    from sklearn.ensemble import RandomForestClassifier
    forest = RandomForestClassifier(n_estimators = 10, criterion = 'entropy', random_state = 0)
    forest.fit(X_train,y_train)
    
    #Print the training accuracy for each model
    print('[0]Logistic Regression Training Accuracy:', log.score(X_train, y_train))
    print('[1]K Neighbors  Training Accuracy:', knn.score(X_train, y_train))
    print('[2]SVC Linear Training Accuracy:', svc_lin.score(X_train, y_train))
    print('[3]SVC RBF Training Accuracy:', svc_rbf.score(X_train, y_train))
    print('[4]Gaussian NB Training Accuracy:', gauss.score(X_train, y_train))
    print('[5]Decision Tree Training Accuracy:', tree.score(X_train, y_train))
    print('[6]Random Forest Training Accuracy:', forest.score(X_train, y_train))
    return log,knn,svc_lin,svc_rbf,gauss,tree,forest

 # 訓練資料集的結果：可以發現 'Decision Tree' 與 'Random Forest' 訓練不錯，訓練資料集準確率高達 95 % 以上。
model = models(X_train, y_train)

# Accuracy 分數: 用[2][5]的訓練成果都不錯
from sklearn.metrics import confusion_matrix

for i in range( len(model) ):
    cm = confusion_matrix(y_test, model[i].predict(X_test))

    # Extract TN, FP, FN, TP
    TN, FP, FN, TP = confusion_matrix(y_test, model[i].predict(X_test)).ravel()
    
    test_score = (TP + TN) / (TN + TP + FP + FN)

    print(cm)
    print('Model[{}] Testing Accuracy = "{}"' .format(i, test_score))
    print()
    
# 進一步觀察 Decision model，重要特徵(欄位)排序哪些影響結果最多 
decisionTree = model[5]
importances = pd.DataFrame({'feature': data.iloc[:, 1:8].columns, 'importance': np.round(decisionTree.feature_importances_, 3)} )
importances = importances.sort_values('importance', ascending = False).set_index('feature')
importances

# visualize the importance
importances.plot.bar()
plt.show()