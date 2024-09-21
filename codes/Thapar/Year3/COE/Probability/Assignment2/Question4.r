data(iris)

cat("4. (a) Head of the iris dataset:\n")
# 4. (a) Displaying the first few rows of the iris dataset
print(head(iris))

cat("\n4. (b) Structure of the iris dataset:\n")
# 4. (b) Displaying the structure of the iris dataset
str(iris)

cat("\n4. (c) Range of Sepal.Length:\n")
# 4. (c) Finding the range of Sepal.Length
cat("Range:", range(iris$Sepal.Length), "\n")

cat("\n4. (d) Mean of Sepal.Length:\n")
# 4. (d) Calculating the mean of Sepal.Length
cat("Mean:", mean(iris$Sepal.Length), "\n")

cat("\n4. (e) Median of Sepal.Length:\n")
# 4. (e) Calculating the median of Sepal.Length
cat("Median:", median(iris$Sepal.Length), "\n")

cat("\n4. (f) Interquartile Range of Sepal.Length:\n")
# 4. (f) Calculating the Interquartile Range (IQR) of Sepal.Length
quartiles <- quantile(iris$Sepal.Length, probs = c(0.25, 0.75))
IQR <- quartiles[2] - quartiles[1]
cat("1st Quartile:", quartiles[1], "3rd Quartile:", quartiles[2], "\n")
cat("Interquartile Range (IQR):", IQR, "\n")

cat("\n4. (g) Standard Deviation and Variance of Sepal.Length:\n")
# 4. (g) Calculating the standard deviation and variance of Sepal.Length
cat("Standard Deviation:", sd(iris$Sepal.Length), "\n")
cat("Variance:", var(iris$Sepal.Length), "\n")

cat("\n4. (h) Mean of Sepal.Width, Petal.Length, and Petal.Width:\n")
# 4. (h) Calculating the mean of Sepal.Width, Petal.Length, and Petal.Width
cat("Mean of Sepal.Width:", mean(iris$Sepal.Width), "\n")
cat("Mean of Petal.Length:", mean(iris$Petal.Length), "\n")
cat("Mean of Petal.Width:", mean(iris$Petal.Width), "\n")

cat("\n4. (i) Summary of the Iris Dataset:\n")
# 4. (i) Displaying the summary of the iris dataset
print(summary(iris))
