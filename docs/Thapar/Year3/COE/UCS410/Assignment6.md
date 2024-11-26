# Assignment 6

## (1) The joint probability density of two random variables X and Y is

$$ f(x, y) =
\begin{cases}
\frac{2 \cdot (2x + 3y)}{5}, & \text{if } 0 \leq x, y \leq 1 \\
0, & \text{elsewhere}
\end{cases}
$$

Then write a R-code to <br>
(i) check that it is a joint density function or not? (Use `integral2()`)<br>
(ii) find marginal distribution g(x) at x = 1.<br>
(iii) find the marginal distribution h(y) at y = 0.<br>
(iv) find the expected value of g(x, y) = xy.
  ```R
  f_xy = function(x,y) {
    ifelse(0 <= x & x <= 1 & 0 <= y & y <= 1, 2*(2*x + 3*y)/5, 0)
  }

  # (i) Check if it is a joint density function
  check = integral2(function(x,y) f_xy(x, y), xmin = 0, xmax = 1, ymin = 0, ymax = 1)

  # (ii) Find the marginal distribution g(x) at x = 1
  g_x = function(x) {
    integrate(function(y) f_xy(x, y), lower = 0, upper = 1)$value
  }
  g_x_at_1 = g_x(1)

  # (iii) Find the marginal distribution h(y) at y = 0
  h_y = function(y){
    integrate(function(x) f_xy(x, y), lower = 0, upper = 1)$value
  }
  h_y_at_0 = h_y(0)

  # (iv) Find the expected value of g(x, y) = xy
  exp_val = integral2(function(x, y) x*y*f_xy(x, y), xmin = 0, xmax = 1, ymin = 0, ymax = 1)$value

  cat("Integral over the domain (should equal 1):", check$value, "\n")
  cat("Marginal distribution g(x) at x = 1:", g_x_at_1, "\n")
  cat("Marginal distribution h(y) at y = 0:", h_y_at_0, "\n")
  cat("Find the expected value of g(x, y) = xy:", exp_val, "\n")
  ```

## (2) The joint probability mass function of two random variables X and Y is
$$ f(x, y) = \{ \frac{(x + y)}{30}; x = 0, 1, 2, 3; y = 0, 1, 2 \} $$

Then write a R-code to <br>
(i) display the joint mass function in rectangular (matrix) form. <br>
(ii) check that it is joint mass function or not? (use: `Sum()`) <br>
(iii) find the marginal distribution g(x) for x = 0, 1, 2, 3. (Use: `apply()`) <br>
(iv) find the marginal distribution h(y) for y = 0, 1, 2. (Use: `apply()`) <br>
(v) find the conditional probability at x = 0 given y = 1. <br>
(vi) find E(x), E(y), E(xy), V ar(x), V ar(y), Cov(x, y) and its correlation coefficient.
  ```R
  x_vals = 0:3
  y_vals = 0:2

  # (i) Display the joint mass function in rectangular (matrix) form
  joint_pmf = outer(x_vals, y_vals, function(x, y) (x + y)/30)
  rownames(joint_pmf) = paste("x =", x_vals)
  colnames(joint_pmf) = paste("y =", y_vals)

  # (ii) Check if it is a joint mass function
  total_prob = sum(joint_pmf)

  # (iii) Find the marginal distribution g(x) for x = 0, 1, 2, 3
  g_x = apply(joint_pmf, 1, sum)

  # (iv) Find the marginal distribution h(y) for y = 0, 1, 2
  h_y = apply(joint_pmf, 2, sum)

  # (v) Find the conditional probability at x = 0 given y = 1
  P_y_1 = h_y[2]
  p_x_0_given_y_1 = joint_pmf[1, 2]/P_y_1

  # (vi) Find E(x), E(y), E(xy), Var(x), Var(y), Cov(x, y) and its correlation coefficient
  E_x = sum(x_vals*g_x)
  E_y = sum(y_vals*h_y)
  E_xy = sum(outer(x_vals, y_vals, function(x, y) x*y)*joint_pmf)

  Var_x = sum((x_vals - E_x)^2*g_x)
  Var_y = sum((y_vals - E_y)^2*h_y)
  Cov_xy = E_xy - E_x*E_y
  corr = Cov_xy/sqrt(Var_x*Var_y)

  cat("Joint PMF:\n", capture.output(print(joint_pmf)), sep="\n")
  cat("Total Probabiltiy (equal to 1):", total_prob, "\n")
  cat("Marginal distribution g(x) for x = 0, 1, 2, 3:", g_x, "\n")
  cat("Marginal distribution h(y) for y = 0, 1, 2:", h_y, "\n")
  cat("P(x = 0 | y = 1):", p_x_0_given_y_1, "\n")
  cat("E(X):", E_x, "\nE(y):", E_y, "\nE(xy):", E_xy, "\nVar(x):", Var_x "\nVar(y):", Var_y, "\nCov(x, y):", Cov_xy, "\nCorrelation Coefficient:", corr, "\n")
  ```
