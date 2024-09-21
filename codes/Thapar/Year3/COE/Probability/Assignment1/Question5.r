x = 1:10
y = x^2
plot(x, y, main="Basic Plot", xlab="x-axis", ylab="y-axis", col="blue", pch=19))

# Box Plot
data <- list(A = rnorm(100, mean = 5), B = rnorm(100, mean = 10), C = rnorm(100, mean = 15))
boxplot(data, main = "Box Plot Example", xlab = "Categories", ylab = "Values")
legend("topright", legend = c("A", "B", "C"), fill = c("white", "white", "white"))

# Pie Chart
slices = c(10, 20, 30, 40)
labels = c("A", "B", "C", "D")
pie(slices, labels=labels, main="Basic Pie Chart")

# Bar Plot
counts_matrix <- matrix(c(10, 15, 20, 25, 12, 18, 22, 28), nrow = 2, ncol = 4, byrow = TRUE)
barplot(counts_matrix, beside = TRUE, main = "Bar Plot with Multiple Bars",
        xlab = "Categories", ylab = "Counts", col = c("green", "blue"),
        legend = c("Group 1", "Group 2"))

# Histogram
hist_data <- rnorm(100, mean = 50, sd = 10)
hist(hist_data, main = "Histogram Example", xlab = "Value", col = "purple", border = "black", breaks = 10)

# Scatter Plot
x_sc = rnorm(100)
y_sc = x_sc + rnorm(100, mean=0.5)
plot(x_sc, y_sc, main="Scatter Plot", xlab="x-axis", ylab="y-axis", col="red", pch=19)
legend("topright", legend = "Scatter Points", col = "red", pch = 19)
