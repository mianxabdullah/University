--Task 2: Monthly Sales of Each Outlet

SELECT s.store_name, d.year, d.month,
       SUM(f.sales_amount) AS monthly_sales
FROM Sales_Fact f
JOIN Dim_Store s ON f.store_key = s.store_key
JOIN Dim_Date d ON f.date_key = d.date_key
GROUP BY s.store_name, d.year, d.month
ORDER BY d.year, d.month;

-- Task 3: Yearly Sales of the Whole Khaadi Brand

SELECT d.year, SUM(f.sales_amount) AS yearly_sales
FROM Sales_Fact f
JOIN Dim_Date d ON f.date_key = d.date_key
GROUP BY d.year
ORDER BY d.year;

-- Task 4: Monthly Articles Sold Across Outlets:

SELECT d.year, d.month,
       SUM(f.quantity_sold) AS articles_sold
FROM Sales_Fact f
JOIN Dim_Date d ON f.date_key = d.date_key
GROUP BY d.year, d.month
ORDER BY d.year, d.month;

-- Task 5: Outlet Generating Maximum Revenue

SELECT TOP 1 s.store_name,
       SUM(f.sales_amount) AS total_revenue
FROM Sales_Fact f
JOIN Dim_Store s ON f.store_key = s.store_key
GROUP BY s.store_name
ORDER BY total_revenue DESC;


-- Task 6: City With the Most Outlets

SELECT TOP 1 WITH TIES city,
       COUNT(*) AS total_outlets
FROM Dim_Store
GROUP BY city
ORDER BY total_outlets DESC;


-- Task 7: Top-Selling Article of June 2025
SELECT TOP 1 p.product_name,
       SUM(f.quantity_sold) AS articles_sold
FROM Sales_Fact f
JOIN Dim_Product p ON f.product_key = p.product_key
JOIN Dim_Date d ON f.date_key = d.date_key
WHERE d.year = 2025 AND d.month = 6
GROUP BY p.product_name
ORDER BY articles_sold DESC;


-- Task 8: Most Demanded Clothing Size at Each Outlet

WITH SizeSales AS (
    SELECT s.store_name, p.size,
           SUM(f.quantity_sold) AS total_sold,
           RANK() OVER (
               PARTITION BY s.store_name
               ORDER BY SUM(f.quantity_sold) DESC
           ) AS rnk
    FROM Sales_Fact f
    JOIN Dim_Store s ON f.store_key = s.store_key
    JOIN Dim_Product p ON f.product_key = p.product_key
    GROUP BY s.store_name, p.size
)
SELECT store_name, size, total_sold
FROM SizeSales
WHERE rnk = 1;


-- Task 9: Best-Selling Clothing Category in Summer

SELECT TOP 1 p.category,
       SUM(f.quantity_sold) AS articles_sold
FROM Sales_Fact f
JOIN Dim_Product p ON f.product_key = p.product_key
JOIN Dim_Date d ON f.date_key = d.date_key
WHERE d.month IN (6, 7, 8)
GROUP BY p.category
ORDER BY articles_sold DESC;