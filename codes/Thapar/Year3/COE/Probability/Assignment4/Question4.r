# Define the probability density function f(x)
f_x = function(x) {
  return(0.5 * exp(-abs(x)))
}

# Calculate the first moment (Mean)
first_moment = integrate(function(x) x * f_x(x), lower = 1, upper = 10)$value

# Calculate the second moment
second_moment = integrate(function(x) x^2 * f_x(x), lower = 1, upper = 10)$value

# Mean and variance
mean_x = first_moment
variance_x = second_moment - mean_x^2

# Output the results
cat("4. Mean and Variance of X\n")
cat("Mean of X is:", mean_x, "\n")
cat("Variance of X is:", variance_x, "\n")
