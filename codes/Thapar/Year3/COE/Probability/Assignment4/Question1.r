# Define the values of X and their probabilities
x = c(0, 1, 2, 3, 4)
p_x = c(0.41, 0.37, 0.16, 0.05, 0.01)

# Calculate the expected value using weighted.mean
expected_value = weighted.mean(x, p_x)
expected_value_matrix <- c(x %*% p_x)

if (expected_value == expected_value_matrix) {
  cat("1. Expected values are the same\n")
} else {
  cat("1. Expected values are different\n")
}
