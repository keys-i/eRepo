# Define the geometric probability function
f_X = function(x) {
  (3/4) * (1/4)^(x - 1)
}

# Define the function to calculate P(Y = X^2)
f_Y = function(x) {
  f_X(x)
}

X = 3
Y = X^2

prob_Y = f_Y(X)

cat("Probability of Y at X =", X, "is", prob_Y, "\n")

# Function to compute expected value and variance of Y for X = 1, 2, 3, 4, 5
expected_value_Y = 0
variance_Y = 0
x_values = 1:5

# Calculate expected value of Y = X^2
for (x in x_values) {
  Y = x^2
  expected_value_Y = expected_value_Y + Y * f_X(x)
  variance_Y = variance_Y + Y^2 * f_X(x)
}

# Adjust variance by subtracting mean squared
variance_Y = variance_Y - expected_value_Y^2

cat("Expected value of Y is: ", expected_value_Y, "\n")
cat("Variance of Y is: ", variance_Y, "\n")
