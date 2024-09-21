#  1. (a)
chest = c(rep("gold", 20), rep("silver", 30), rep("bronze", 50))
# Randomly draw 10 coins
draw = sample(chest, size=10, replace=FALSE)

cat("Sample Size: ", draw, "\n");

# Q1.
#  1. (b)
outcomes = c("'Success", "'Failure")
probabilities = c(0.9, 0.1)

surgery_out = sample(outcomes, size=10, replace=TRUE, prob=probabilities)

cat("Sample Space for next 10 surgical procedures: ", surgery_out)
