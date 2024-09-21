# Assignment 2

## Q1.
(a) Suppose there is a chest of coins with 20 gold, 30 silver and 50 bronze coins.
You randomly draw 10 coins from this chest. Write an R code which will give us the
sample space for this experiment.<br>
(use of `sample()`: an in-built function in R)<br>
(b) In a surgical procedure, the chances of success and failure are 90% and 10% respectively.
Generate a sample space for the next 10 surgical procedures performed.
<br>(use of `prob()`: an in-built function in R)
### 1. (a)
  ```R
  chest = c(rep("gold", 20), rep("silver", 30), rep("bronze", 50))
  # Randomly draw 10 coins
  draw = sample(chest, size=10, replace=FALSE)

  cat("1. (a) Sample Size:", draw, "\n");
  ```

### 1. (b)
  ```R
  outcomes = c("Success", "Failure")
  probabilities = c(0.9, 0.1)

  surgery_out = sample(outcomes, size=10, replace=TRUE, prob=probabilities)

  cat("   (b) Sample Space for next 10 surgical procedures:", surgery_out, "\n")
  ```

## Q2. A room has n people, and each has an equal chance of being born on any of the 365 days of the year. (For simplicity, we’ll ignore leap years). What is the probability that two people in the room have the same birthday?
(a) Use an R simulation to estimate this for various n.<br>
(b) Find the smallest value of n for which the probability of a match is greater than 5.
### 2. (a)
  ```R
  birth_sim = function(n, trials = 10000) {
    count = 0
    for (i in 1:trials) {
      birth = sample(1:365, size=n, replace=TRUE)
      if (length(unique(birth)) < n) {
        count = count + 1
      }
    }
    return (count / trials)
  }

  cat("2. (a) Probability of matching birthdays for n = 1 to 50:\n")
  for (n in 1:50) {
    cat("    For n =", n, "probability of matching birthdays is:", birth_sim(n), "\n")
  }
  ```

### 2. (b)
  ```R
  small_n = function() {
    n = 1
    while (birth_sim(n) < 0.5) {
      n = n + 1
    }
    return(n)
  }

  cat("   (b) Smallest n for which probability of matching birthdays is just above 50% is:", small_n(), "\n")
  ```

## Q3. Write an R function for computing conditional probability. Call this function to do the following problem:
suppose the probability of the weather being cloudy is 40%.
Also suppose the probability of rain on a given day is 20% and that the probability of clouds on a rainy day is 85%.
If it’s cloudy outside on a given day, what is the probability that it will rain that day?
  ```R
  cond_prob = function(p_a_and_b, p_b) {
    return(p_a_and_b / p_b)
  }

  p_cloudy = 0.4
  p_rain = 0.2
  p_cloud_and_rain = 0.85

  p_cloudy_given_rain <- 0.85

  # Calculate P(rain and cloudy)
  p_rain_and_cloudy <- p_rain * p_cloudy_given_rain

  # Calculate conditional probability
  p_rain_given_cloudy <- cond_prob(p_rain_and_cloudy, p_cloudy)

  # Output the result
  cat("3. Probability of Rain Given Cloudy is:", p_rain_given_cloudy, "\n")
  ```

## Q4. The iris dataset is a built-in dataset in R that contains measurements on 4 different attributes (in centimeters) for 150 flowers from 3 different species. Load this dataset and do the following:
(a) Print first few rows of this dataset.<br>
(b) Find the structure of this dataset.<br>
(c) Find the range of the data regarding the sepal length of flowers.<br>
(d) Find the mean of the sepal length.<br>
(e) Find the median of the sepal length.<br>
(f) Find the first and the third quartiles and hence the interquartile range.<br>
(g) Find the standard deviation and variance.<br>
(h) Try doing the above exercises for sepal.width, petal.length and petal.width.<br>
(i) Use the built-in function summary on the dataset Iris.
  ```R
  data(iris)

  cat("4. (a) Head of the iris dataset:\n")
  # 4. (a) Displaying the first few rows of the iris dataset
  print(head(iris))

  cat("\n4. (b) Structure of the iris dataset:\n")
  # 4. (b) Displaying the structure of the iris dataset
  str(iris)

  cat("\n4. (c) Range of Sepal.Length:\n")
  # 4. (c) Finding the range of Sepal.Length
  cat("Range:", range(iris$Sepal.Length), "\n")

  cat("\n4. (d) Mean of Sepal.Length:\n")
  # 4. (d) Calculating the mean of Sepal.Length
  cat("Mean:", mean(iris$Sepal.Length), "\n")

  cat("\n4. (e) Median of Sepal.Length:\n")
  # 4. (e) Calculating the median of Sepal.Length
  cat("Median:", median(iris$Sepal.Length), "\n")

  cat("\n4. (f) Interquartile Range of Sepal.Length:\n")
  # 4. (f) Calculating the Interquartile Range (IQR) of Sepal.Length
  quartiles <- quantile(iris$Sepal.Length, probs = c(0.25, 0.75))
  IQR <- quartiles[2] - quartiles[1]
  cat("1st Quartile:", quartiles[1], "3rd Quartile:", quartiles[2], "\n")
  cat("Interquartile Range (IQR):", IQR, "\n")

  cat("\n4. (g) Standard Deviation and Variance of Sepal.Length:\n")
  # 4. (g) Calculating the standard deviation and variance of Sepal.Length
  cat("Standard Deviation:", sd(iris$Sepal.Length), "\n")
  cat("Variance:", var(iris$Sepal.Length), "\n")

  cat("\n4. (h) Mean of Sepal.Width, Petal.Length, and Petal.Width:\n")
  # 4. (h) Calculating the mean of Sepal.Width, Petal.Length, and Petal.Width
  cat("Mean of Sepal.Width:", mean(iris$Sepal.Width), "\n")
  cat("Mean of Petal.Length:", mean(iris$Petal.Length), "\n")
  cat("Mean of Petal.Width:", mean(iris$Petal.Width), "\n")

  cat("\n4. (i) Summary of the Iris Dataset:\n")
  # 4. (i) Displaying the summary of the iris dataset
  print(summary(iris))
  ```

## Q5. R does not have a standard in-built function to calculate mode. So we create a user function to calculate mode of a data set in R. This function takes the vector as input and gives the mode value as output.
  ```R
  gmode = function(v) {
    uniqv = unique(v)
    uniqv[which.max(tabulate(match(v, uniqv)))]
  }

  v = c(2, 3, 3, 5, 5, 5, 7)
  cat("5. Mode among [", paste(v, collapse = ", "), "] is:", gmode(v), "\n")
  ```
