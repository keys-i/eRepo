# Q3.
#  3. (a) Probability that no car arrives between 10 AM and 11 AM
p_no_car = dpois(0, lambda=5)
cat("Probability that no car arrives between 10 AM and 11 AM is: ", p_no_car, "\n")

#  3. (b) Probability that between 48 and 50 customers arrive between 8AM and 6PM (10 hours)
# - P(48 <= Y <= 50) = P(Y <= 50) - P(Y <= 47)
p_48_to_50 <- ppois(50, lambda_total) - ppois(47, lambda_total)

cat("Probability that between 48 and 50 customers arrive between 8AM and 6PM is: ", p_48_to_50, "\n")
