# Assignment 7

## (1) Use the `rt(n, df)` function in r to investigate the t-distribution for n = 100 and df = n − 1 and plot the histogram for the same.
  ```R
  n = 100; df = n-1
  t_vals = rt(n, df)
  hist(t_vals, breaks = 30, freq = FALSE, xlab = "Values", main = "Histogram of t-Distribution (n = 100, df = 99)")
  lines(density(t_vals), col = "blue")
  ```

## (2) Use the `rchisq(n, df)` function in r to investigate the chi-square distribution with n = 100 and df = 2, 10, 25.
  ```R
  n = 100; df_vals = c(2, 10, 25)
  chi_sq_vals = lapply(df_vals, function(df) {
    hist(rchisq(n, df), breaks = 30, freq = FALSE, xlab = "Values", main = paste("Histogram of Chi-Square Distribution (n = 100, df =", df, ")")
  })
  par(mfrow = c(1, 1))
  ```

## (3) Generate a vector of 100 values between -6 and 6. Use the `dt()` function in r to find the values of a t-distribution given a random variable x and degrees of freedom 1,4,10,30. Using these values plot the density function for students t-distribution with degrees of freedom 30. Also shows a comparison of probability density functions having different degrees of freedom (1,4,10,30).
  ```R
  x = seq(-6, 6, length = 100); df_vals = c(1, 4, 10, 30)
  dense_vals = lapply(df_vals, function(df) dt(x, df))
  plot(x, dense_vals[, 4], type = "l", main = "t-Density (df=30)", xlab = "x", ylab = "Density")
  plot(x, dense_vals[, 1], type = "l", col = 1, main = "Comparison of t-Densities", xlab = "x", ylab = "Density")
  lapply(2:4, function(i) lines(x, dense_vals[, i], col = i))
  legend("topright", legend = paste("df=", df_vals), col = 1:4, lwd = 2)
  ```

## (4) Write a r-code
(i) To find the 95th percentile of the F-distribution with (10, 20) degrees of freedom. <br>
(ii) To calculate the area under the curve for the interval [0, 1.5] and the interval [1.5, +∞) of a F-curve with v1 = 10 and v2 = 20 (use `pf()`). <br>
(iii) To calculate the quantile for a given area (= probability) under the curve for a F-curve with v1 = 10 and v2 = 20 that corresponds to q = 0.25, 0.5, 0.75 and 0.999. (use the `qf()`) <br>
(iv) To generate 1000 random values from the F-distribution with v1 = 10 and v2 = 20 (use `rf()`)and plot a histogram.
  ```R
  v1 = 10 v2 = 20
  # (i) 95th percentile of F-distribution with (10, 20) degrees of freedom
  qf_95_percentile = qf(0.95, v1, v2)

  # (ii) Area under the curve for the interval [0, 1.5] and [1.5, +∞) of F-curve with v1 = 10 and v2 = 20
  pf_0_1_5 = pf(1.5, v1, v2); pf_1_5_inf = 1 - pf_0_1_5

  # (iii) Quantile for a given area under the curve for F-curve with v1 = 10 and v2 = 20 that corresponds to q = 0.25, 0.5, 0.75 and 0.999
  qf_vals = qf(c(0.25, 0.5, 0.75, 0.999), v1, v2)

  # (iv) Generate 1000 random values from F-distribution with v1 = 10 and v2 = 20 and plot a histogram
  rf = rf(1000, v1, v2)
  hist(rf, breaks = 30, freq = FALSE, main = "F-Distribution (10,20)", xlab = "Values")

  cat("95th percentile of F-distribution with (10, 20) degrees of freedom: ", qf_95_percentile, "\n")
  cat("Area under the curve for the interval [0, 1.5] of F-curve with v1 = 10 and v2 = 20: ", pf_0_1_5, " and [1.5, +∞): ", pf_1_5_inf, "\n")
  cat("Quantile for a given area under the curve for F-curve with v1 = 10 and v2 = 20 that corresponds to q = 0.25, 0.5, 0.75 and 0.999: ", qf_vals, "\n")
  ```
