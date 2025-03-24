"""
day 1: machine learning
"""

#comment
#importing the datasets
import numpy as np  #array matrix calculation
import matplotlib.pyplot as plt  
import pandas as pd   #used to deal with dataset

#importing the dataset
dataset =pd.read_csv('Salary_Data_v.csv')
x = dataset.iloc[:, :-1].values
y = dataset.iloc[:,1].values

#splitting the dataset