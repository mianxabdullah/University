USE master;
GO

IF DB_ID('KhaadiDW_OneStar') IS NULL
BEGIN
    CREATE DATABASE KhaadiDW_OneStar;
END;
GO

USE KhaadiDW_OneStar;
GO

SET NOCOUNT ON;
GO

DROP TABLE IF EXISTS dbo.Sales_Fact;
DROP TABLE IF EXISTS dbo.Dim_Product;
DROP TABLE IF EXISTS dbo.Dim_Store;
DROP TABLE IF EXISTS dbo.Dim_Date;
DROP TABLE IF EXISTS dbo.Dim_Customer;
DROP TABLE IF EXISTS dbo.Dim_Channel;
GO

CREATE TABLE dbo.Dim_Product (
    product_key INT IDENTITY(1,1) PRIMARY KEY,
    product_id VARCHAR(50) NOT NULL,
    product_name VARCHAR(150) NOT NULL,
    category VARCHAR(100),
    brand VARCHAR(100),
    size VARCHAR(20),
    color VARCHAR(50),
    season VARCHAR(50)
);
GO

CREATE TABLE dbo.Dim_Store (
    store_key INT IDENTITY(1,1) PRIMARY KEY,
    store_id VARCHAR(50) NOT NULL,
    store_name VARCHAR(150) NOT NULL,
    city VARCHAR(100),
    region VARCHAR(100),
    store_type VARCHAR(50),
    location VARCHAR(250)
);
GO

CREATE TABLE dbo.Dim_Date (
    date_key INT PRIMARY KEY,
    full_date DATE NOT NULL,
    day_of_week VARCHAR(20),
    month INT,
    quarter INT,
    year INT,
    season VARCHAR(50)
);
GO

CREATE TABLE dbo.Dim_Customer (
    customer_key INT IDENTITY(1,1) PRIMARY KEY,
    customer_id VARCHAR(50) NOT NULL,
    customer_name VARCHAR(150),
    gender VARCHAR(20),
    age_group VARCHAR(30),
    city VARCHAR(100),
    loyalty_member BIT
);
GO

CREATE TABLE dbo.Dim_Channel (
    channel_key INT IDENTITY(1,1) PRIMARY KEY,
    channel_id VARCHAR(50) NOT NULL,
    channel_name VARCHAR(100),
    channel_type VARCHAR(50)
);
GO

CREATE TABLE dbo.Sales_Fact (
    sales_key BIGINT IDENTITY(1,1) PRIMARY KEY,
    date_key INT NOT NULL,
    store_key INT NOT NULL,
    product_key INT NOT NULL,
    customer_key INT NOT NULL,
    channel_key INT NOT NULL,
    quantity_sold INT NOT NULL DEFAULT 0,
    sales_amount DECIMAL(18,2) NOT NULL DEFAULT 0,
    cost_amount DECIMAL(18,2) NOT NULL DEFAULT 0,
    discount_amount DECIMAL(18,2) NOT NULL DEFAULT 0,
    profit_amount DECIMAL(18,2) NOT NULL DEFAULT 0,
    CONSTRAINT FK_Sales_Date FOREIGN KEY (date_key)
        REFERENCES dbo.Dim_Date(date_key),
    CONSTRAINT FK_Sales_Store FOREIGN KEY (store_key)
        REFERENCES dbo.Dim_Store(store_key),
    CONSTRAINT FK_Sales_Product FOREIGN KEY (product_key)
        REFERENCES dbo.Dim_Product(product_key),
    CONSTRAINT FK_Sales_Customer FOREIGN KEY (customer_key)
        REFERENCES dbo.Dim_Customer(customer_key),
    CONSTRAINT FK_Sales_Channel FOREIGN KEY (channel_key)
        REFERENCES dbo.Dim_Channel(channel_key)
);
GO

;WITH ProductNumbers AS (
    SELECT TOP (100)
        ROW_NUMBER() OVER (ORDER BY (SELECT NULL)) AS n
    FROM sys.all_objects a
    CROSS JOIN sys.all_objects b
)
INSERT INTO dbo.Dim_Product
    (product_id, product_name, category, brand, size, color, season)
SELECT
    CONCAT('KH-', RIGHT('0000' + CAST(n AS VARCHAR(4)), 4)),
    CONCAT(
        CASE (n - 1) % 8
            WHEN 0 THEN 'Embroidered'
            WHEN 1 THEN 'Printed'
            WHEN 2 THEN 'Casual'
            WHEN 3 THEN 'Formal'
            WHEN 4 THEN 'Lawn'
            WHEN 5 THEN 'Cotton'
            WHEN 6 THEN 'Linen'
            ELSE 'Festive'
        END,
        ' ',
        CASE (n - 1) % 6
            WHEN 0 THEN 'Kurta'
            WHEN 1 THEN 'Shalwar Kameez'
            WHEN 2 THEN 'Tunic'
            WHEN 3 THEN 'Dupatta'
            WHEN 4 THEN 'Trousers'
            ELSE 'Dress'
        END,
        ' ',
        n
    ),
    CASE (n - 1) % 6
        WHEN 0 THEN 'Unstitched'
        WHEN 1 THEN 'Ready to Wear'
        WHEN 2 THEN 'Kurtas'
        WHEN 3 THEN 'Dupattas'
        WHEN 4 THEN 'Bottoms'
        ELSE 'Accessories'
    END,
    'Khaadi',
    CASE (n - 1) % 6
        WHEN 0 THEN 'XS'
        WHEN 1 THEN 'S'
        WHEN 2 THEN 'M'
        WHEN 3 THEN 'L'
        WHEN 4 THEN 'XL'
        ELSE 'Free Size'
    END,
    CASE (n - 1) % 8
        WHEN 0 THEN 'Black'
        WHEN 1 THEN 'White'
        WHEN 2 THEN 'Blue'
        WHEN 3 THEN 'Green'
        WHEN 4 THEN 'Red'
        WHEN 5 THEN 'Beige'
        WHEN 6 THEN 'Pink'
        ELSE 'Mustard'
    END,
    CASE (n - 1) % 4
        WHEN 0 THEN 'Summer'
        WHEN 1 THEN 'Winter'
        WHEN 2 THEN 'Spring'
        ELSE 'Autumn'
    END
FROM ProductNumbers;
GO

INSERT INTO dbo.Dim_Store
    (store_id, store_name, city, region, store_type, location)
VALUES
('ST001', 'Khaadi Lahore MM Alam', 'Lahore', 'Punjab', 'Flagship', 'MM Alam Road'),
('ST002', 'Khaadi Lahore Emporium', 'Lahore', 'Punjab', 'Mall', 'Emporium Mall'),
('ST003', 'Khaadi Lahore Packages', 'Lahore', 'Punjab', 'Mall', 'Packages Mall'),
('ST004', 'Khaadi Karachi Dolmen Clifton', 'Karachi', 'Sindh', 'Mall', 'Dolmen Mall Clifton'),
('ST005', 'Khaadi Karachi Lucky One', 'Karachi', 'Sindh', 'Mall', 'Lucky One Mall'),
('ST006', 'Khaadi Karachi Tariq Road', 'Karachi', 'Sindh', 'Retail', 'Tariq Road'),
('ST007', 'Khaadi Islamabad Centaurus', 'Islamabad', 'ICT', 'Mall', 'Centaurus Mall'),
('ST008', 'Khaadi Islamabad F-7', 'Islamabad', 'ICT', 'Retail', 'F-7 Markaz'),
('ST009', 'Khaadi Rawalpindi', 'Rawalpindi', 'Punjab', 'Retail', 'Commercial Market'),
('ST010', 'Khaadi Faisalabad', 'Faisalabad', 'Punjab', 'Retail', 'D Ground'),
('ST011', 'Khaadi Multan', 'Multan', 'Punjab', 'Retail', 'Gulgasht Colony'),
('ST012', 'Khaadi Gujranwala', 'Gujranwala', 'Punjab', 'Retail', 'Satellite Town'),
('ST013', 'Khaadi Peshawar', 'Peshawar', 'Khyber Pakhtunkhwa', 'Retail', 'University Road'),
('ST014', 'Khaadi Abbottabad', 'Abbottabad', 'Khyber Pakhtunkhwa', 'Retail', 'Main Bazaar'),
('ST015', 'Khaadi Quetta', 'Quetta', 'Balochistan', 'Retail', 'Jinnah Road'),
('ST016', 'Khaadi Hyderabad', 'Hyderabad', 'Sindh', 'Retail', 'Autobahn Road'),
('ST017', 'Khaadi Sialkot', 'Sialkot', 'Punjab', 'Retail', 'Paris Road'),
('ST018', 'Khaadi Bahawalpur', 'Bahawalpur', 'Punjab', 'Retail', 'Circular Road'),
('ST019', 'Khaadi Sargodha', 'Sargodha', 'Punjab', 'Retail', 'Satellite Town'),
('ST020', 'Khaadi Online Fulfillment', 'Lahore', 'Punjab', 'Online Fulfillment', 'Central Warehouse');
GO

;WITH DateSeries AS (
    SELECT CAST('2024-01-01' AS DATE) AS dt
    UNION ALL
    SELECT DATEADD(DAY, 1, dt)
    FROM DateSeries
    WHERE dt < CAST('2026-12-31' AS DATE)
)
INSERT INTO dbo.Dim_Date
    (date_key, full_date, day_of_week, month, quarter, year, season)
SELECT
    YEAR(dt) * 10000 + MONTH(dt) * 100 + DAY(dt),
    dt,
    DATENAME(WEEKDAY, dt),
    MONTH(dt),
    DATEPART(QUARTER, dt),
    YEAR(dt),
    CASE
        WHEN MONTH(dt) IN (3, 4, 5) THEN 'Spring'
        WHEN MONTH(dt) IN (6, 7, 8) THEN 'Summer'
        WHEN MONTH(dt) IN (9, 10, 11) THEN 'Autumn'
        ELSE 'Winter'
    END
FROM DateSeries
OPTION (MAXRECURSION 0);
GO

;WITH CustomerNumbers AS (
    SELECT TOP (200)
        ROW_NUMBER() OVER (ORDER BY (SELECT NULL)) AS n
    FROM sys.all_objects a
    CROSS JOIN sys.all_objects b
)
INSERT INTO dbo.Dim_Customer
    (customer_id, customer_name, gender, age_group, city, loyalty_member)
SELECT
    CONCAT('CUS', RIGHT('0000' + CAST(n AS VARCHAR(4)), 4)),
    CONCAT(
        CASE (n - 1) % 20
            WHEN 0 THEN 'Ayesha'
            WHEN 1 THEN 'Fatima'
            WHEN 2 THEN 'Zainab'
            WHEN 3 THEN 'Hira'
            WHEN 4 THEN 'Maryam'
            WHEN 5 THEN 'Ali'
            WHEN 6 THEN 'Ahmed'
            WHEN 7 THEN 'Usman'
            WHEN 8 THEN 'Hamza'
            WHEN 9 THEN 'Bilal'
            WHEN 10 THEN 'Sara'
            WHEN 11 THEN 'Maham'
            WHEN 12 THEN 'Hassan'
            WHEN 13 THEN 'Omar'
            WHEN 14 THEN 'Iqra'
            WHEN 15 THEN 'Laiba'
            WHEN 16 THEN 'Danish'
            WHEN 17 THEN 'Noor'
            WHEN 18 THEN 'Saad'
            ELSE 'Amna'
        END,
        ' Customer ',
        n
    ),
    CASE
        WHEN n % 10 IN (0, 1, 2, 3, 4, 5) THEN 'Female'
        ELSE 'Male'
    END,
    CASE
        WHEN n % 4 = 0 THEN '18-25'
        WHEN n % 4 = 1 THEN '26-35'
        WHEN n % 4 = 2 THEN '36-45'
        ELSE '46+'
    END,
    CASE (n - 1) % 10
        WHEN 0 THEN 'Lahore'
        WHEN 1 THEN 'Karachi'
        WHEN 2 THEN 'Islamabad'
        WHEN 3 THEN 'Rawalpindi'
        WHEN 4 THEN 'Faisalabad'
        WHEN 5 THEN 'Multan'
        WHEN 6 THEN 'Peshawar'
        WHEN 7 THEN 'Quetta'
        WHEN 8 THEN 'Hyderabad'
        ELSE 'Sialkot'
    END,
    CASE WHEN n % 100 < 35 THEN 1 ELSE 0 END
FROM CustomerNumbers;
GO

INSERT INTO dbo.Dim_Channel
    (channel_id, channel_name, channel_type)
VALUES
('CH001', 'Physical Retail Store', 'Offline'),
('CH002', 'Official Website', 'Online'),
('CH003', 'Mobile App', 'Online'),
('CH004', 'Online Marketplace', 'Online');
GO

;WITH TransactionNumbers AS (
    SELECT TOP (5000)
        ROW_NUMBER() OVER (ORDER BY (SELECT NULL)) AS n
    FROM sys.all_objects a
    CROSS JOIN sys.all_objects b
),
TransactionDetails AS (
    SELECT
        n,
        DATEADD(
            DAY,
            (n * 37) % 1096,
            CAST('2024-01-01' AS DATE)
        ) AS transaction_date,
        ((n * 7) % 20) + 1 AS store_key,
        ((n * 13) % 100) + 1 AS product_key,
        ((n * 17) % 200) + 1 AS customer_key,
        ((n * 19) % 4) + 1 AS channel_key,
        ((n * 11) % 5) + 1 AS quantity_sold,
        CAST(1200 + ((n * 137) % 8800) AS DECIMAL(18,2)) AS unit_price,
        CAST(0.10 + ((n * 7) % 21) / 100.0 AS DECIMAL(5,2)) AS discount_rate,
        CAST(0.40 + ((n * 3) % 21) / 100.0 AS DECIMAL(5,2)) AS cost_rate
    FROM TransactionNumbers
),
CalculatedSales AS (
    SELECT
        n,
        transaction_date,
        store_key,
        product_key,
        customer_key,
        channel_key,
        quantity_sold,
        CAST(unit_price * quantity_sold AS DECIMAL(18,2)) AS gross_amount,
        discount_rate,
        cost_rate
    FROM TransactionDetails
)
INSERT INTO dbo.Sales_Fact
    (date_key, store_key, product_key, customer_key, channel_key,
     quantity_sold, sales_amount, cost_amount, discount_amount, profit_amount)
SELECT
    YEAR(transaction_date) * 10000
        + MONTH(transaction_date) * 100
        + DAY(transaction_date),
    store_key,
    product_key,
    customer_key,
    channel_key,
    quantity_sold,
    CAST(gross_amount * (1 - discount_rate) AS DECIMAL(18,2)),
    CAST(gross_amount * cost_rate AS DECIMAL(18,2)),
    CAST(gross_amount * discount_rate AS DECIMAL(18,2)),
    CAST(
        gross_amount * (1 - discount_rate)
        - gross_amount * cost_rate
        AS DECIMAL(18,2)
    )
FROM CalculatedSales;
GO

SELECT 'Dim_Product' AS table_name, COUNT_BIG(*) AS total_rows FROM dbo.Dim_Product
UNION ALL
SELECT 'Dim_Store', COUNT_BIG(*) FROM dbo.Dim_Store
UNION ALL
SELECT 'Dim_Date', COUNT_BIG(*) FROM dbo.Dim_Date
UNION ALL
SELECT 'Dim_Customer', COUNT_BIG(*) FROM dbo.Dim_Customer
UNION ALL
SELECT 'Dim_Channel', COUNT_BIG(*) FROM dbo.Dim_Channel
UNION ALL
SELECT 'Sales_Fact', COUNT_BIG(*) FROM dbo.Sales_Fact;
GO

SELECT TOP (20)
    sf.sales_key,
    dd.full_date,
    ds.store_name,
    dp.product_name,
    dc.customer_name,
    dch.channel_name,
    sf.quantity_sold,
    sf.sales_amount,
    sf.cost_amount,
    sf.discount_amount,
    sf.profit_amount
FROM dbo.Sales_Fact sf
INNER JOIN dbo.Dim_Date dd ON sf.date_key = dd.date_key
INNER JOIN dbo.Dim_Store ds ON sf.store_key = ds.store_key
INNER JOIN dbo.Dim_Product dp ON sf.product_key = dp.product_key
INNER JOIN dbo.Dim_Customer dc ON sf.customer_key = dc.customer_key
INNER JOIN dbo.Dim_Channel dch ON sf.channel_key = dch.channel_key
ORDER BY sf.sales_key;
GO

SELECT
    COUNT_BIG(*) AS total_transactions,
    SUM(quantity_sold) AS total_units_sold,
    SUM(sales_amount) AS total_net_sales_pkr,
    SUM(cost_amount) AS total_cost_pkr,
    SUM(discount_amount) AS total_discount_pkr,
    SUM(profit_amount) AS total_profit_pkr
FROM dbo.Sales_Fact;
GO

SELECT
    dd.year,
    COUNT_BIG(*) AS total_transactions,
    SUM(sf.quantity_sold) AS units_sold,
    SUM(sf.sales_amount) AS total_sales_pkr,
    SUM(sf.profit_amount) AS total_profit_pkr
FROM dbo.Sales_Fact sf
INNER JOIN dbo.Dim_Date dd ON sf.date_key = dd.date_key
GROUP BY dd.year
ORDER BY dd.year;
GO

SELECT
    dp.category,
    SUM(sf.quantity_sold) AS units_sold,
    SUM(sf.sales_amount) AS total_sales_pkr,
    SUM(sf.profit_amount) AS total_profit_pkr
FROM dbo.Sales_Fact sf
INNER JOIN dbo.Dim_Product dp ON sf.product_key = dp.product_key
GROUP BY dp.category
ORDER BY total_sales_pkr DESC;
GO

SELECT
    dch.channel_name,
    COUNT_BIG(*) AS total_transactions,
    SUM(sf.sales_amount) AS total_sales_pkr,
    SUM(sf.profit_amount) AS total_profit_pkr
FROM dbo.Sales_Fact sf
INNER JOIN dbo.Dim_Channel dch ON sf.channel_key = dch.channel_key
GROUP BY dch.channel_name
ORDER BY total_sales_pkr DESC;
GO

PRINT 'KhaadiDW_OneStar created and populated successfully.';
GO




; Test the Db created successfully 

USE KhaadiDW_OneStar;
GO

SELECT 'Dim_Product' AS TableName, COUNT(*) AS TotalRows
FROM dbo.Dim_Product

UNION ALL

SELECT 'Dim_Store', COUNT(*)
FROM dbo.Dim_Store

UNION ALL

SELECT 'Dim_Date', COUNT(*)
FROM dbo.Dim_Date

UNION ALL

SELECT 'Dim_Customer', COUNT(*)
FROM dbo.Dim_Customer

UNION ALL

SELECT 'Dim_Channel', COUNT(*)
FROM dbo.Dim_Channel

UNION ALL

SELECT 'Sales_Fact', COUNT(*)
FROM dbo.Sales_Fact;
GO