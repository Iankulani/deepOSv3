import numpy as np
from sklearn.ensemble import RandomForestClassifier

def detect_malware(features):
    model = RandomForestClassifier()
    model.load("malware_model.pkl")
    return model.predict([features])[0]