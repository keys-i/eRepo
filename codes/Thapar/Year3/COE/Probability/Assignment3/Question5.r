# 5. (a) Distribution of X
cat("5. (a) X is distributed as Binomial with parameters n = 31 and p = 0.447:\n")
cat("X ~ Binomial(n = 31, p = 0.447)\n")

# 5. (b) Sketch the Probability Mass Function (PMF)
n <- 31
p <- 0.447
x_vals <- 0:n
pmf_vals <- dbinom(x_vals, n, p)

# Plot the PMF
plot(x_vals, pmf_vals, type = "h", lwd = 2, col = "blue",
     xlab = "Number of Students Using Wikipedia", ylab = "Probability",
     main = "Probability Mass Function of X")
grid()

# 5. (c) Sketch the Cumulative Distribution Function (CDF)
# Calculate the CDF
cdf_vals <- pbinom(x_vals, n, p)

# Plot the CDF
plot(x_vals, cdf_vals, type = "s", lwd = 2, col = "red",
     xlab = "Number of Students Using Wikipedia", ylab = "Cumulative Probability",
     main = "Cumulative Distribution Function of X")
grid()

# 5. (d) Find mean, variance, and standard deviation of X
mean_x <- n * p
variance_x <- n * p * (1 - p)
sd_x <- sqrt(variance_x)

cat("\n5. (d) Mean, Variance, and Standard Deviation of X:\n")
cat("Mean of X: ", mean_x, "\n")
cat("Variance of X: ", variance_x, "\n")
cat("Standard Deviation of X: ", sd_x, "\n")
