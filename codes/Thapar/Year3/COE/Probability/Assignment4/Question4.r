f_x = function(x) {
  return(0.5 * exp(-abs(x)))
}

# First moment (Mean)
first_moment = integrate(function(x) x * f_x(x), lower = 1, upper = 10)$value

# Second moment
second_moment = integrate(function(x) x^2 * f_x(x), lower = 1, upper = 10)$value

# Mean and variance
mean = first_moment
variance = second_moment - mean_X^2

# Output the results
cat("Mean of X is: ", mean, "\n")
cat("Variance of X is: ", variance, "\n")
