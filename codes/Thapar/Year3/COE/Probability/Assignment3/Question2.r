mean = 72
sd = 15.2

p_84_or_more = 1 - pnorm(84, mean, sd)

cat("2. Percentage of students scoring 84 or more in the exam is:", p_84_or_more * 100, "%\n")
