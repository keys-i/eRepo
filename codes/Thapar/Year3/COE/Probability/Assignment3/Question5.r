# Q5.
#  5. (a) How is X distributed?
cat("X ~ Binomial(n = 31, p = 0.447)\n")

#  5. (b) Sketch the probability mass function.
x_vals = 0:n
pmf_vals = dbinom(x_vals, n, p)

# Plot the PMF
plot(x_values, pmf_values, type = "h", lwd = 2, col = "blue",
     xlab = "Number of Students Using Wikipedia", ylab = "Probability",
     main = "Probability Mass Function of X")

#  5. (c) Sketch the cumulative distribution function.
# Calculate the CDF
cdf_values <- pbinom(x_values, n, p)

# Plot the CDF
cdf_values <- pbinom(x_values, n, p)

plot(x_values, cdf_values, type = "s", lwd = 2, col = "red",
     xlab = "Number of Students Using Wikipedia", ylab = "Cumulative Probability",
     main = "Cumulative Distribution Function of X")

#  5. (d) Find mean, variance and standard deviation of X
# X ~ Binomial(n, p)
# mean = n * p
# variance = n * p * (1 - p)
mean = n * p
variance = n * p * (1 - p)

sd = sqrt(variance)

cat("Mean of X: ", mean, "\n")
cat("Standard Deviation of x: ", sd, "\n")
