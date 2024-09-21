# Assignment 4

## Q1. The probability distribution of X, the number of imperfections per 10 meters of a synthetic fabric in continuous rolls of uniform width, is given as

| x   | 0   | 1   | 2   | 3   | 4   |
|-----|-----|-----|-----|-----|-----|
| p(x)| 0.41| 0.37| 0.16| 0.05| 0.01|

Find the average number of imperfections per 10 meters of this fabric.
(Try functions `sum( )`, `weighted.mean( )`, `c(a %*% b)` to find expected value/mean.
  ```R
  # Define the values of X and their probabilities
  x = c(0, 1, 2, 3, 4)
  p_x = c(0.41, 0.37, 0.16, 0.05, 0.01)

  # Calculate the expected value using weighted.mean
  expected_value = weighted.mean(x, p_x)
  expected_value_matrix <- c(x %*% p_x)

  if (expected_value == expected_value_matrix) {
    cat("Expected values are the same")
  } else {
    cat("Expected values are different")
  }
  ```

## Q2. The time T, in days, required for the completion of a contracted project is a random variable with probability density function \( f(t) = 0.1 e^{(-0.1t)} \) for t > 0 and 0 otherwise. Find the expected value of T.
Use function integrate( ) to find the expected value of continuous random variable T.
  ```R
  f = function(t) {
    return(0.1 * exp(-0.1 * t))
  }

  expected_value_t = integrate(function(t) t * f(t), lower = 0, upper = Inf)$value

  cat("Expected value of T is: ", expected_value_t)
  ```

## Q3. A bookstore purchases three copies of a book at $6.00 each and sells them for $12.00 each. Unsold copies are returned for $2.00 each. Let X = {number of copies sold} and Y = {net revenue}. If the probability mass function of X is

| x    | 0   | 1   | 2   | 3   |
|------|-----|-----|-----|-----|
| p(x) | 0.1 | 0.2 | 0.2 | 0.5 |

Find the expected value of Y.
  ```R
  x = c(0, 1, 2, 3)
  p_x = c(0.1, 0.2, 0.2, 0.5)

  # Net Revenue = (Revenue from sold books) - (Cost of purchased books) + (Refund from unsold books)
  Y = function(x) {
    return((12 * x - 6 * 3) + (3 - x) * 2)
  }

  expected_value_y = sum(p_x * Y(x))

  cat("Expected value of Y is: ", expected_value_y, "\n")
  ```

## Q4. Find the first and second moments about the origin of the random variable X with probability density function \( f(x) = 0.5e^{-|x|} \), 1 < x < 10 and 0 otherwise. Further use the results to find Mean and Variance.
(kth moment = \( E(X^k) \) , Mean = first moment and Variance = second moment – \( Mean^2 \).
  ```R
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
  ```

## Q5. Let X be a geometric random variable with probability distribution
$$ f(x) = \frac{3}{4} \left( \frac{1}{4}\right)^{x-1} \hspace{3cm},x= 1,2,3,\dots $$

Write a function to find the probability distribution of the random variable \( Y = X^2 \) and
find probability of Y for \( X = 3 \). Further, use it to find the expected value and variance of
Y for \( X = 1,2,3,4,5 \).
  ```R
  # Define the geometric probability function
  f_X <- function(x) {
    (3/4) * (1/4)^(x - 1)
  }

  # Define the function to calculate P(Y = X^2)
  f_Y <- function(x) {
    f_X(x)
  }

  X = 3
  Y = X^2

  prob_Y <- f_Y(X)

  cat("Probability of Y at X =", X, "is", prob_Y, "\n")

  # Function to compute expected value and variance of Y for X = 1, 2, 3, 4, 5
  expected_value_Y <- 0
  variance_Y <- 0
  x_values <- 1:5

  # Calculate expected value of Y = X^2
  for (x in x_values) {
    Y <- x^2
    expected_value_Y <- expected_value_Y + Y * f_X(x)
    variance_Y <- variance_Y + Y^2 * f_X(x)
  }

  # Adjust variance by subtracting mean squared
  variance_Y <- variance_Y - expected_value_Y^2

  cat("Expected value of Y is: ", expected_value_Y, "\n")
  cat("Variance of Y is: ", variance_Y, "\n")
  ```
