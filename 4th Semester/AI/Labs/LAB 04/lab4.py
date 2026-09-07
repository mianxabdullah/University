import pandas as pd
import numpy as np
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score, precision_score, recall_score, classification_report, confusion_matrix
import warnings
warnings.filterwarnings('ignore')

class LoanApprovalModel:    
    def __init__(self):
        self.train_data = None
        self.test_data = None
        self.X_train = None
        self.X_test = None
        self.y_train = None
        self.y_test = None
        self.encoders = {}
        
    def load_data(self):
        print("Loading data...")
        self.train_data = pd.read_csv('train_data.csv')
        self.test_data = pd.read_csv('test_data.csv')
        print(f"Training data shape: {self.train_data.shape}")
        print(f"Test data shape: {self.test_data.shape}")
        
    def preprocess(self, df, is_test=False):
        df = df.copy()
        
        numerical_cols = ['ApplicantIncome', 'CoapplicantIncome', 'LoanAmount', 'Loan_Amount_Term']
        for col in numerical_cols:
            if col in df.columns:
                df[col].fillna(df[col].median(), inplace=True)
        
        categorical_cols = ['Gender', 'Married', 'Dependents', 'Education', 'Self_Employed', 'Credit_History']
        for col in categorical_cols:
            if col in df.columns:
                df[col].fillna(df[col].mode()[0] if len(df[col].mode()) > 0 else 'Unknown', inplace=True)
        
        for col in categorical_cols:
            if col in df.columns:
                if col not in self.encoders:
                    self.encoders[col] = LabelEncoder()
                    df[col] = self.encoders[col].fit_transform(df[col])
                else:
                    df[col] = self.encoders[col].transform(df[col])
        
        if 'Property_Area' in df.columns:
            if 'Property_Area' not in self.encoders:
                self.encoders['Property_Area'] = LabelEncoder()
                df['Property_Area'] = self.encoders['Property_Area'].fit_transform(df['Property_Area'])
            else:
                df['Property_Area'] = self.encoders['Property_Area'].transform(df['Property_Area'])
        
        if 'Loan_ID' in df.columns:
            df.drop('Loan_ID', axis=1, inplace=True)
        
        return df
    
    def prepare_data(self):
        print("\nPreprocessing data...")
        
        train_processed = self.preprocess(self.train_data)
        
        X = train_processed.drop('Loan_Status', axis=1)
        y = train_processed['Loan_Status'].map({'Y': 1, 'N': 0})
        
        self.X_train, self.X_test, self.y_train, self.y_test = train_test_split(
            X, y, test_size=0.2, random_state=42
        )
        
        print(f"Training set size: {self.X_train.shape}")
        print(f"Test set size: {self.X_test.shape}")


class DecisionTreeModel(LoanApprovalModel):
    def __init__(self):
        super().__init__()
        self.models = {}
        self.results = {}
        
    def train(self, depths):
        print("\n" + "="*80)
        print("DECISION TREE CLASSIFIER")
        print("="*80)
        
        for depth in depths:
            print(f"\nTraining Decision Tree with max_depth = {depth}...")
            model = DecisionTreeClassifier(max_depth=depth, random_state=42)
            model.fit(self.X_train, self.y_train)
            self.models[depth] = model
            
    def predict(self, depths):
        for depth in depths:
            y_pred = self.models[depth].predict(self.X_test)
            accuracy = accuracy_score(self.y_test, y_pred)
            precision = precision_score(self.y_test, y_pred, zero_division=0)
            recall = recall_score(self.y_test, y_pred, zero_division=0)
            
            self.results[depth] = {
                'accuracy': accuracy,
                'precision': precision,
                'recall': recall,
                'predictions': y_pred
            }
            
    def evaluate(self):
        print("\n" + "-"*80)
        print("DECISION TREE RESULTS")
        print("-"*80)
        
        sorted_results = sorted(self.results.items(), key=lambda x: (x[0] is None, x[0]))
        
        for depth, metrics in sorted_results:
            print(f"\nDepth = {depth}:")
            print(f"  Accuracy:  {metrics['accuracy']:.4f}")
            print(f"  Precision: {metrics['precision']:.4f}")
            print(f"  Recall:    {metrics['recall']:.4f}")
            
            y_pred = metrics['predictions']
            print(f"\n  Confusion Matrix:")
            cm = confusion_matrix(self.y_test, y_pred)
            print(f"  {cm}")


class RandomForestModel(LoanApprovalModel):
    def __init__(self):
        super().__init__()
        self.models = {}
        self.results = {}
        
    def train(self, estimators_list):
        print("\n" + "="*80)
        print("RANDOM FOREST CLASSIFIER")
        print("="*80)
        
        for n_est in estimators_list:
            print(f"\nTraining Random Forest with n_estimators = {n_est}...")
            model = RandomForestClassifier(n_estimators=n_est, random_state=42, n_jobs=-1)
            model.fit(self.X_train, self.y_train)
            self.models[n_est] = model
            
    def predict(self, estimators_list):
        for n_est in estimators_list:
            y_pred = self.models[n_est].predict(self.X_test)
            accuracy = accuracy_score(self.y_test, y_pred)
            precision = precision_score(self.y_test, y_pred, zero_division=0)
            recall = recall_score(self.y_test, y_pred, zero_division=0)
            
            self.results[n_est] = {
                'accuracy': accuracy,
                'precision': precision,
                'recall': recall,
                'predictions': y_pred
            }
            
    def evaluate(self):
        print("\n" + "-"*80)
        print("RANDOM FOREST RESULTS")
        print("-"*80)
        
        for n_est, metrics in sorted(self.results.items()):
            print(f"\nn_estimators = {n_est}:")
            print(f"  Accuracy:  {metrics['accuracy']:.4f}")
            print(f"  Precision: {metrics['precision']:.4f}")
            print(f"  Recall:    {metrics['recall']:.4f}")
            
            y_pred = metrics['predictions']
            print(f"\n  Confusion Matrix:")
            cm = confusion_matrix(self.y_test, y_pred)
            print(f"  {cm}")


def compare_models(dt_model, rf_model):
    print("\n" + "="*80)
    print("COMPARISON: DECISION TREE vs RANDOM FOREST")
    print("="*80)
    
    print("\nDECISION TREE Performance Summary:")
    print("-" * 50)
    sorted_dt_results = sorted(dt_model.results.items(), key=lambda x: (x[0] is None, x[0]))
    for depth, metrics in sorted_dt_results:
        print(f"Depth {depth}: Accuracy={metrics['accuracy']:.4f}, Precision={metrics['precision']:.4f}, Recall={metrics['recall']:.4f}")
    
    print("\nRANDOM FOREST Performance Summary:")
    print("-" * 50)
    for n_est, metrics in sorted(rf_model.results.items()):
        print(f"n_est {n_est}: Accuracy={metrics['accuracy']:.4f}, Precision={metrics['precision']:.4f}, Recall={metrics['recall']:.4f}")
    
    best_dt = max(dt_model.results.items(), key=lambda x: x[1]['accuracy'])
    best_rf = max(rf_model.results.items(), key=lambda x: x[1]['accuracy'])
    
    print("\n" + "-"*50)
    print(f"\nBest Decision Tree (Depth={best_dt[0]}): Accuracy = {best_dt[1]['accuracy']:.4f}")
    print(f"Best Random Forest (n_estimators={best_rf[0]}): Accuracy = {best_rf[1]['accuracy']:.4f}")
    
    if best_rf[1]['accuracy'] > best_dt[1]['accuracy']:
        diff = best_rf[1]['accuracy'] - best_dt[1]['accuracy']
        print(f"\n✓ Random Forest outperforms Decision Tree by {diff:.4f}")
    else:
        diff = best_dt[1]['accuracy'] - best_rf[1]['accuracy']
        print(f"\n✓ Decision Tree outperforms Random Forest by {diff:.4f}")
    
    print("\nAnalysis:")
    print("- Decision Trees tend to overfit with larger depths")
    print("- Random Forests reduce overfitting through ensemble learning")
    print("- Higher n_estimators generally improve Random Forest performance")
    print("- Tree depth should be carefully tuned to avoid overfitting")


def main():
    print("\n" + "="*80)
    print("LOAN APPROVAL PREDICTION: DECISION TREE & RANDOM FOREST ANALYSIS")
    print("="*80)
    
    dt_model = DecisionTreeModel()
    dt_model.load_data()
    dt_model.prepare_data()
    
    depths = [2, 5, None]
    dt_model.train(depths)
    dt_model.predict(depths)
    dt_model.evaluate()
    
    rf_model = RandomForestModel()
    rf_model.X_train = dt_model.X_train
    rf_model.X_test = dt_model.X_test
    rf_model.y_train = dt_model.y_train
    rf_model.y_test = dt_model.y_test
    
    estimators = [10, 50, 100]
    rf_model.train(estimators)
    rf_model.predict(estimators)
    rf_model.evaluate()

    compare_models(dt_model, rf_model)
    
    print("\n" + "="*80)
    print("ANALYSIS COMPLETE")
    print("="*80 + "\n")


if __name__ == "__main__":
    main()
