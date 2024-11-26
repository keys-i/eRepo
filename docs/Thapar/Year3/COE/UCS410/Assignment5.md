# Assignment 5

## 1. Consider that X is the time (in minutes) that a person has to wait in order to take a flight. If each flight takes off each hour \(X \sim U(0, 60)\). Find the probability that <br>
(a) waiting time is more than 45 minutes, and <br>
(b) waiting time lies between 20 and 30 minutes.
  ```R
  min = 0
  max = 60

  # (a) P(X > 45)
  P_more_45 = 1 - punif(45, min, max)

  # (b) P(20 <= X <= 30)
  P_20_30 = punif(30, min, max) - punif(20, min, max)

  cat("P(X > 45) = ", P_more_45, "\nP(20 <= X <= 30) = ", P_20_30, "\n")
  ```

## 2. The time (in hours) required to repair a machine is an exponential distributed random variable with parameter \( \lambda = \frac{1}{2} \). <br>
(a) Find the value of density function at x = 3.<br>
(b) Plot the graph of exponential probability distribution for \( 0 \leq x \leq 5 \).<br>
(c​) Find the probability that a repair time takes at most 3 hours.<br>
(d) Plot the graph of cumulative exponential probabilities for \( 0 \leq x \leq 5 \).<br>
(e) Simulate 1000 exponential distributed random numbers with \( \lambda = \frac{1}{2} \) and plot the
simulated data.
  ```R
  lambda = 1/2
  # (a) Value at density at x = 3
  density_at_3 = dexp(3, lambda)

  # (b) Plot of exponential probability distribution for 0 <= x <= 5
  x = seq(0, 5, 0.01)
  y = dexp(x, rate = lambda)
  plot(x, y, type = "l", col = "blue", xlab = "x", ylab = "Density", main = "Exponential Probability Distribution")

  # (c) Probability that a repair time takes at most 3 hours
  p_at_most_3 = pexp(3, rate = lambda)

  # (d) Plot the graph of cummilative exponential probabilities for 0 <= x <= 5
  y_cdf = pexp(x, rate = lambda)
  plot(x, y_cdf, type = "l", col = "red", xlab = "x", ylab = "Cumulative Probability", main = "Exponential Cumulative Probability Distribution")

  # (e) Simulate 1000 exponential random numbers and plot
  sim_data = rexp(1000, rate = lambda)
  hist(sim_data, breaks, freq = FALSE, col = "green", xlab = "x", ylab = "Frequency", main = "Simulated Exponential Random Numbers")

  cat("Density at x = 3: ", density_at_3, "\n")
  cat("P(X <= 3) = ", p_at_most_3, "\n")
  ```

## 3. The lifetime of certain equipment is described by a random variable X that follows Gamma distribution with parameters \( \alpha = 2 \) and \( \beta = \frac{1}{3} \). <br>
(a) Find the probability that the lifetime of equipment is <br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;(i) 3 units of time, and <br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;(ii) at least 1 unit of time. <br>
(b) What is the value of c, if \( P(X \leq c) \geq 0.70 \)? (Hint: try quantile function `qgamma()`)
  ```R
  alpha = 2
  beta = 1/3

  # (a) Probability that the lifetime of equipment is
  # (i) P(X <= 3)
  P_leq_3 = pgamma(3, shape = alpha, rate = beta)

  # (ii) P(X >= 1)
  P_geq_1 = 1 - pgamma(1, shape = alpha, rate = beta)

  # (b) Find c such that P(X <= c) >= 0.70
  c_val = qgamma(0.70, shape = alpha, rate = beta)

  cat("P(X <= 3):", P_leq_3, "\n")
  cat("P(X >= 1):", P_geq_1, "\n")
  cat("Value of c (P(X <= c) >= 0.70)", c_val, "\n")
  ```
