size = 12
prob = 1/6

p_7_to_9 = pbinom(9, size, prob) - pbinom(6, size, prob)

cat("1. Probability of getting 7, 8 or 9, 6’s is:", p_7_to_9, "\n")
