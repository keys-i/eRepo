# Assignment 3

## Q1. Roll 12 dice simultaneously, and let X denotes the number of 6’s that appear. Calculate the probability of getting 7, 8 or 9, 6’s using R.
(Try using the function `pbinom()`; If we set S = {get a 6 on one roll}, \( P(S) = 1/6 \) and the rolls constitute Bernoulli trials; thus \( X ∼ binom(size=12, prob=1/6) \) and we are looking for \( P(7 ≤ X ≤ 9) \).
  ```R
  size = 12
  prob = 1/6

  p_7_to_9 = pbinom(9, size, prob) - pbinom(6, size, prob)

  cat("1. Probability of getting 7, 8 or 9, 6’s is:", p_7_to_9, "\n")
  ```

## Q2. Assume that the test scores of a college entrance exam fits a normal distribution. Furthermore, the mean test score is 72, and the standard deviation is 15.2. What is the percentage of students scoring 84 or more in the exam?
  ```R
  mean = 72
  sd = 15.2

  p_84_or_more = 1 - pnorm(84, mean, sd)

  cat("2. Percentage of students scoring 84 or more in the exam is:", p_84_or_more * 100, "%\n")
  ```

## Q3. On the average, five cars arrive at a particular car wash every hour. Let X count the number of cars that arrive from 10AM to 11AM, then \( X ∼ Poisson(λ = 5) \). What is probability that no car arrives during this time. Next, suppose the car wash above is in operation from 8AM to 6PM, and we let Y be the number of customers that appear in this period. Since this period covers a total of 10 hours, we get that \( Y ∼ Poisson(λ = 5 × 10 = 50) \). What is the probability that there are between 48 and 50 customers, inclusive?
  ```R
  # a. Probability that no car arrives between 10 AM and 11 AM
  p_no_car = dpois(0, lambda=5)
  cat("1. (a) Probability that no car arrives between 10 AM and 11 AM is: ", p_no_car, "\n")

  # b. Probability that between 48 and 50 customers arrive between 8AM and 6PM (10 hours)
  # - P(48 <= Y <= 50) = P(Y <= 50) - P(Y <= 47)
  p_48_to_50 = ppois(50, lambda=5*10) - ppois(47, lambda=5*10)

  cat("   (b) Probability that between 48 and 50 customers arrive between 8AM and 6PM is:", p_48_to_50, "\n")
  ```

## Q4. Suppose in a certain shipment of 250 Pentium processors there are 17 defective processors. A quality control consultant randomly collects 5 processors for inspection to determine whether or not they are defective. Let X denote the number of defectives in the sample. Find the probability of exactly 3 defectives in the sample, that is, find P(X = 3).
  ```R
  # Parameters for the hypergeometric distribution
  m = 17   # number of defective processors
  n = 250 - 17  # number of non-defective processors
  k = 5    # sample size

  # P(X = 3) for X ~ Hypergeometric(m = 17, n = 233, k = 5)
  p_exactly_3_defectives = dhyper(3, m, n, k)

  cat("4. Probability of exactly 3 defectives in the sample is:", p_exactly_3_defectives, "\n")
  ```

## Q5. A recent national study showed that approximately 44.7% of college students have used Wikipedia as a source in at least one of their term papers. Let X equal the number of students in a random sample of size n = 31 who have used Wikipedia as a source.
(a) How is X distributed?<br>
(b) Sketch the probability mass function.<br>
(c​) Sketch the cumulative distribution function.<br>
(d) Find mean, variance and standard deviation of X
  ```R
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
  cat("Standard Deviation of X: ", sd_x, "\n")s
  ```
