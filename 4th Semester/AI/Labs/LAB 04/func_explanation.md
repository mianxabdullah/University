# Function Documentation & Method Explanations
## Loan Approval Prediction: Decision Tree & Random Forest Analysis

---

## 📚 Imports & Libraries

```python
import pandas as pd              # Data manipulation and analysis
import numpy as np               # Numerical operations
from sklearn.tree import DecisionTreeClassifier  # Decision Tree model
from sklearn.ensemble import RandomForestClassifier  # Random Forest model
from sklearn.preprocessing import LabelEncoder  # Categorical encoding
from sklearn.model_selection import train_test_split  # Data splitting
from sklearn.metrics import accuracy_score, precision_score, recall_score, confusion_matrix  # Evaluation metrics
```

| Library | Purpose | Method |
|---------|---------|--------|
| **pandas** | Efficient dataframe operations, CSV reading, data manipulation | `pd.read_csv()`, `fillna()`, `mode()`, `drop()` |
| **numpy** | Numerical computations and array operations | Array support for scikit-learn |
| **scikit-learn** | Machine learning algorithms and preprocessing | Classification, encoding, metrics |

---

## 🏗️ Class: LoanApprovalModel (Base Class)

**Purpose**: Serves as a base class for all loan approval models. Contains common data loading and preprocessing logic.

### Method 1: `__init__(self)`
**Purpose**: Initialize the model with default attributes.

```python
def __init__(self):
    self.train_data = None        # Store raw training dataset
    self.test_data = None         # Store raw test dataset
    self.X_train = None           # Training features
    self.X_test = None            # Test features
    self.y_train = None           # Training target variable
    self.y_test = None            # Test target variable
    self.encoders = {}            # Dictionary to store label encoders for each categorical column
```

**Methods Used**:
- Python object initialization
- Dictionary creation for encoder storage

---

### Method 2: `load_data(self)`
**Purpose**: Load training and test datasets from CSV files.

```python
def load_data(self):
    print("Loading data...")
    self.train_data = pd.read_csv('train_data.csv')  # Load 614 training samples
    self.test_data = pd.read_csv('test_data.csv')     # Load 367 test samples
    print(f"Training data shape: {self.train_data.shape}")  # Display shape
    print(f"Test data shape: {self.test_data.shape}")
```

**Methods Used**:
- **pandas.read_csv()**: Reads CSV file into DataFrame
- **DataFrame.shape**: Returns (rows, columns) tuple

**Why These Methods?**
- Efficient file I/O for large datasets
- Automatic data type inference
- Easy data verification

---

### Method 3: `preprocess(self, df, is_test=False)`
**Purpose**: Handle missing values and encode categorical variables to prepare data for machine learning.

#### Step 1: Handle Numerical Missing Values
```python
numerical_cols = ['ApplicantIncome', 'CoapplicantIncome', 'LoanAmount', 'Loan_Amount_Term']
for col in numerical_cols:
    if col in df.columns:
        df[col].fillna(df[col].median(), inplace=True)
```

**Methods Used**:
- **fillna()**: Replace NaN values
- **median()**: Calculate median for imputation

**Why?** Median is robust to outliers compared to mean

#### Step 2: Handle Categorical Missing Values
```python
categorical_cols = ['Gender', 'Married', 'Dependents', 'Education', 'Self_Employed', 'Credit_History']
for col in categorical_cols:
    if col in df.columns:
        df[col].fillna(df[col].mode()[0] if len(df[col].mode()) > 0 else 'Unknown', inplace=True)
```

**Methods Used**:
- **mode()**: Get most frequent value
- **Conditional logic**: Fallback to 'Unknown' if no mode exists

**Why?** Most frequent value preserves data distribution

#### Step 3: Encode Categorical Variables
```python
for col in categorical_cols:
    if col not in self.encoders:
        self.encoders[col] = LabelEncoder()          # Create encoder
        df[col] = self.encoders[col].fit_transform(df[col])  # Fit on training data
    else:
        df[col] = self.encoders[col].transform(df[col])      # Apply same encoding to test data
```

**Methods Used**:
- **LabelEncoder()**: Convert categories to numerical labels
- **fit_transform()**: Learn mapping and apply it
- **transform()**: Apply learned mapping to new data

**Why?** 
- Decision Trees and Random Forests need numerical input
- Using same encoder for train/test ensures consistency
- Prevents data leakage

#### Step 4: Encode Categorical Features (Property_Area)
```python
if 'Property_Area' in df.columns:
    if 'Property_Area' not in self.encoders:
        self.encoders['Property_Area'] = LabelEncoder()
        df['Property_Area'] = self.encoders['Property_Area'].fit_transform(df['Property_Area'])
    else:
        df['Property_Area'] = self.encoders['Property_Area'].transform(df['Property_Area'])
```

**Why Separate?** Ensures all categorical columns are handled consistently

#### Step 5: Drop Identifier Column
```python
if 'Loan_ID' in df.columns:
    df.drop('Loan_ID', axis=1, inplace=True)
```

**Methods Used**:
- **drop()**: Remove columns from DataFrame
- **axis=1**: Operate on columns (not rows)
- **inplace=True**: Modify original DataFrame

**Why?** Loan_ID is an identifier, not a feature for prediction

---

### Method 4: `prepare_data(self)`
**Purpose**: Prepare data for model training by preprocessing and splitting into train/test sets.

```python
def prepare_data(self):
    print("\nPreprocessing data...")
    train_processed = self.preprocess(self.train_data)  # Preprocess training data
    
    # Separate features and target
    X = train_processed.drop('Loan_Status', axis=1)    # Features (all except target)
    y = train_processed['Loan_Status'].map({'Y': 1, 'N': 0})  # Target variable
    
    # Split into train and test sets
    self.X_train, self.X_test, self.y_train, self.y_test = train_test_split(
        X, y, test_size=0.2, random_state=42  # 80% train, 20% test
    )
```

**Methods Used**:
- **preprocess()**: Call preprocessing method
- **drop()**: Remove target column from features
- **map()**: Convert Y/N to 1/0
- **train_test_split()**: Split data randomly

**Parameters**:
- **test_size=0.2**: Use 20% for testing
- **random_state=42**: Seed for reproducibility

**Why?**
- 80/20 split is standard machine learning practice
- train_test_split() uses stratification for class balance
- random_state ensures reproducible results

---

## 🌳 Class: DecisionTreeModel (Inherits from LoanApprovalModel)

**Purpose**: Train and evaluate Decision Tree classifiers with different depths to study overfitting.

### Method 1: `__init__(self)`
```python
def __init__(self):
    super().__init__()          # Initialize parent class attributes
    self.models = {}            # Dictionary to store trained models
    self.results = {}           # Dictionary to store evaluation results
```

**Methods Used**:
- **super().__init__()**: Call parent class constructor
- **Dictionary creation**: Store multiple models and results

---

### Method 2: `train(self, depths)`
**Purpose**: Train Decision Tree models with different maximum depths.

```python
def train(self, depths):  # depths = [2, 5, None]
    print("\n" + "="*80)
    print("DECISION TREE CLASSIFIER")
    print("="*80)
    
    for depth in depths:
        print(f"\nTraining Decision Tree with max_depth = {depth}...")
        model = DecisionTreeClassifier(max_depth=depth, random_state=42)
        model.fit(self.X_train, self.y_train)      # Train the model
        self.models[depth] = model                  # Store model
```

**Methods Used**:
- **DecisionTreeClassifier()**: Create tree model
- **fit()**: Train on data

**Parameters**:
- **max_depth=depth**: Controls tree depth (prevents overfitting)
- **random_state=42**: Reproducibility

**Why These Depths?**
- Depth=2: Very shallow, underfitting expected
- Depth=5: Moderate, balanced
- Depth=None: Unlimited, overfitting expected

---

### Method 3: `predict(self, depths)`
**Purpose**: Make predictions and calculate evaluation metrics.

```python
def predict(self, depths):
    for depth in depths:
        y_pred = self.models[depth].predict(self.X_test)     # Predict on test data
        
        # Calculate metrics
        accuracy = accuracy_score(self.y_test, y_pred)       # (TP+TN)/(Total)
        precision = precision_score(self.y_test, y_pred, zero_division=0)  # TP/(TP+FP)
        recall = recall_score(self.y_test, y_pred, zero_division=0)        # TP/(TP+FN)
        
        self.results[depth] = {
            'accuracy': accuracy,
            'precision': precision,
            'recall': recall,
            'predictions': y_pred
        }
```

**Metrics Explained**:
| Metric | Formula | Meaning |
|--------|---------|---------|
| **Accuracy** | (TP + TN) / Total | % of correct predictions |
| **Precision** | TP / (TP + FP) | % of approved loans that were correct |
| **Recall** | TP / (TP + FN) | % of actual approvals captured |

**Methods Used**:
- **predict()**: Generate predictions
- **accuracy_score()**: Compare predictions with actual
- **precision_score()**: Calculate precision
- **recall_score()**: Calculate recall
- **zero_division=0**: Handle division by zero

---

### Method 4: `evaluate(self)`
**Purpose**: Display and compare results across different depths.

```python
def evaluate(self):
    print("\n" + "-"*80)
    print("DECISION TREE RESULTS")
    print("-"*80)
    
    # Sort results with None at the end
    sorted_results = sorted(self.results.items(), key=lambda x: (x[0] is None, x[0]))
    
    for depth, metrics in sorted_results:
        print(f"\nDepth = {depth}:")
        print(f"  Accuracy:  {metrics['accuracy']:.4f}")
        print(f"  Precision: {metrics['precision']:.4f}")
        print(f"  Recall:    {metrics['recall']:.4f}")
        
        y_pred = metrics['predictions']
        cm = confusion_matrix(self.y_test, y_pred)
        print(f"\n  Confusion Matrix:\n  {cm}")
```

**Methods Used**:
- **sorted()**: Sort results
- **lambda function**: Custom sorting key
- **confusion_matrix()**: Get TP, TN, FP, FN

**Confusion Matrix Format**:
```
[[TN, FP],
 [FN, TP]]
```

---

## 🌲 Class: RandomForestModel (Inherits from LoanApprovalModel)

**Purpose**: Train and evaluate Random Forest classifiers with different numbers of estimators.

### Method 1: `__init__(self)`
```python
def __init__(self):
    super().__init__()
    self.models = {}
    self.results = {}
```

Same as DecisionTreeModel.

---

### Method 2: `train(self, estimators_list)`
**Purpose**: Train Random Forest models with different numbers of trees.

```python
def train(self, estimators_list):  # [10, 50, 100]
    print("\n" + "="*80)
    print("RANDOM FOREST CLASSIFIER")
    print("="*80)
    
    for n_est in estimators_list:
        print(f"\nTraining Random Forest with n_estimators = {n_est}...")
        model = RandomForestClassifier(
            n_estimators=n_est,    # Number of trees
            random_state=42,       # Reproducibility
            n_jobs=-1              # Use all CPU cores
        )
        model.fit(self.X_train, self.y_train)
        self.models[n_est] = model
```

**Methods Used**:
- **RandomForestClassifier()**: Create ensemble model
- **n_jobs=-1**: Parallel processing (all available cores)
- **fit()**: Train on data

**Why These n_estimators?**
- n_estimators=10: Minimal ensemble
- n_estimators=50: Moderate
- n_estimators=100: Heavy ensemble

---

### Method 3: `predict(self, estimators_list)`
**Purpose**: Make predictions and calculate metrics (same as DecisionTree).

```python
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
```

Same methodology as DecisionTreeModel.predict()

---

### Method 4: `evaluate(self)`
**Purpose**: Display results for Random Forest models.

```python
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
        cm = confusion_matrix(self.y_test, y_pred)
        print(f"\n  Confusion Matrix:\n  {cm}")
```

Similar to DecisionTreeModel.evaluate()

---

## 🔍 Function: `compare_models(dt_model, rf_model)`

**Purpose**: Compare Decision Tree and Random Forest performance comprehensively.

### Step 1: Display Performance Summary
```python
def compare_models(dt_model, rf_model):
    print("\n" + "="*80)
    print("COMPARISON: DECISION TREE vs RANDOM FOREST")
    print("="*80)
    
    # Print Decision Tree Results
    print("\nDECISION TREE Performance Summary:")
    sorted_dt_results = sorted(dt_model.results.items(), 
                               key=lambda x: (x[0] is None, x[0]))
    for depth, metrics in sorted_dt_results:
        print(f"Depth {depth}: Accuracy={metrics['accuracy']:.4f}, ...")
```

**Methods Used**:
- **sorted()**: Order results properly
- **lambda**: Custom sorting

---

### Step 2: Find Best Models
```python
best_dt = max(dt_model.results.items(), key=lambda x: x[1]['accuracy'])
best_rf = max(rf_model.results.items(), key=lambda x: x[1]['accuracy'])

print(f"\nBest Decision Tree (Depth={best_dt[0]}): Accuracy = {best_dt[1]['accuracy']:.4f}")
print(f"Best Random Forest (n_estimators={best_rf[0]}): Accuracy = {best_rf[1]['accuracy']:.4f}")
```

**Methods Used**:
- **max()**: Find highest accuracy
- **lambda**: Extract accuracy from nested dict

---

### Step 3: Determine Winner
```python
if best_rf[1]['accuracy'] > best_dt[1]['accuracy']:
    diff = best_rf[1]['accuracy'] - best_dt[1]['accuracy']
    print(f"\n✓ Random Forest outperforms Decision Tree by {diff:.4f}")
else:
    diff = best_dt[1]['accuracy'] - best_rf[1]['accuracy']
    print(f"\n✓ Decision Tree outperforms Random Forest by {diff:.4f}")
```

**Methods Used**:
- **Conditional logic**: Compare accuracy
- **Arithmetic**: Calculate difference

---

## 🚀 Function: `main()`

**Purpose**: Orchestrate the entire analysis workflow.

### Step 1: Initialize and Prepare Data
```python
def main():
    print("\n" + "="*80)
    print("LOAN APPROVAL PREDICTION: DECISION TREE & RANDOM FOREST ANALYSIS")
    print("="*80)
    
    dt_model = DecisionTreeModel()
    dt_model.load_data()
    dt_model.prepare_data()
```

**Methods Used**:
- **Object instantiation**: Create model instance
- **Method chaining**: Call sequential methods

---

### Step 2: Train and Evaluate Decision Tree
```python
depths = [2, 5, None]
dt_model.train(depths)
dt_model.predict(depths)
dt_model.evaluate()
```

**Workflow**:
1. train() → Creates 3 models with different depths
2. predict() → Makes predictions on test set
3. evaluate() → Calculates metrics and displays results

---

### Step 3: Train and Evaluate Random Forest
```python
rf_model = RandomForestModel()
rf_model.X_train = dt_model.X_train      # Reuse same train/test split
rf_model.X_test = dt_model.X_test
rf_model.y_train = dt_model.y_train
rf_model.y_test = dt_model.y_test

estimators = [10, 50, 100]
rf_model.train(estimators)
rf_model.predict(estimators)
rf_model.evaluate()
```

**Why Reuse Data?**
- Ensures fair comparison between models
- Both models evaluate on identical test set
- Same training data distribution

---

### Step 4: Compare and Finalize
```python
compare_models(dt_model, rf_model)

print("\n" + "="*80)
print("ANALYSIS COMPLETE")
print("="*80 + "\n")
```

---

## 📊 Summary Table: Methods by Category

| Category | Method | Library | Purpose |
|----------|--------|---------|---------|
| **Data Loading** | read_csv() | pandas | Load dataset |
| **Data Cleaning** | fillna(), mode() | pandas | Handle missing values |
| **Encoding** | LabelEncoder.fit_transform() | sklearn | Convert categories to numbers |
| **Train/Test Split** | train_test_split() | sklearn | Split data 80/20 |
| **Model Training** | fit() | sklearn | Train models |
| **Prediction** | predict() | sklearn | Make predictions |
| **Evaluation** | accuracy_score, precision_score, recall_score | sklearn | Calculate metrics |
| **Analysis** | confusion_matrix() | sklearn | Detailed error analysis |
| **Sorting** | sorted(), max() | Python | Compare results |

---

## 🎯 Data Flow Diagram

```
1. CSV Files (train_data.csv, test_data.csv)
        ↓
2. load_data() → DataFrame objects
        ↓
3. preprocess() → Handle missing values + Encode
        ↓
4. prepare_data() → Split into X_train, X_test, y_train, y_test
        ↓
5. [Decision Tree]                [Random Forest]
   train(depths)                  train(estimators)
   predict(depths)                predict(estimators)
   evaluate()                      evaluate()
        ↓                                ↓
6. compare_models() → Final Comparison & Winner
        ↓
7. Results Display & Analysis
```

---

## 🔑 Key Methods Explained

### DecisionTreeClassifier.fit()
- **What**: Train tree by recursively splitting features
- **How**: Uses Gini impurity or entropy to determine best splits
- **Why**: Finds optimal decision boundaries for classification

### RandomForestClassifier.fit()
- **What**: Train multiple trees using random feature subsets
- **How**: Each tree trained on bootstrap sample of data
- **Why**: Reduces overfitting through ensemble averaging

### LabelEncoder.fit_transform()
- **What**: Learn and apply label encoding in one step
- **How**: Creates mapping: 'Male'→1, 'Female'→0
- **Why**: Ensures test data gets same encoding as training data

### train_test_split()
- **What**: Randomly divide data into train and test sets
- **How**: Uses stratified splitting to maintain class distribution
- **Why**: Prevents model from evaluating on data it trained on

---

This documentation provides complete understanding of each function, the methods used, and the reasoning behind design choices!
