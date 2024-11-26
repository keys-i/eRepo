# Assignment 8
## 1. A pipe manufacturing organization produces different kinds of pipes. We are given the monthly data of the wall thickness of certain types of pipes (data is available on LMS Clt-data.csv).
The organization has an analysis to perform and one of the basic assumption of that analysis is that the data should be normally distributed. <br>
You have the following tasks to do: <br>
(a) Import the csv data file in R.<br>
(b) Validate data for correctness by counting number of rows and viewing the top ten rows of the dataset.<br>
(c​) Calculate the population mean and plot the observations by making a histogram.<br>
(d) Mark the mean computed in last step by using the function abline.<br>

See the red vertical line in the histogram? That’s the population mean. Comment on
whether the data is normally distributed or not? <br>
Now perform the following tasks: <br>
(a) Draw sufficient samples of size 10, calculate their means, and plot them in R by making histogram. Do you get a normal distribution. <br>
(b) Now repeat the same with sample size 50, 500 and 9000. Can you comment on what you observe. <br>
> Here, we get a good bell-shaped curve and the sampling distribution approaches
> normal distribution as the sample sizes increase. Therefore, we can recommend the
> organization to use sampling distributions of mean for further analysis.

  ```R
  # (a) Import the csv
  data = read.csv("Clt-data.csv")

  # (b) Validate data
  cat("Number of rows:", nrow(data), "\n")
  cat("Top 10 rows:\n", capture.output(head(data, 10)), sep = "\n")

  # (c) Calculate population mean and plot histogram
  pop_mean = mean(data$WallThickness, na.rm = TRUE)
  cat("Population mean:", pop_mean, "\n")
  hist(data$WallThickness, breaks = 30, freq = FALSE, col = "lightblue", xlab = "Wall Thickness", main = "Wall Thickness of Pipes")

  # (d) Mark the mean in histogram
  abline(v = pop_mean, col = "red", lwd = 2, lty = 2)

  # (a) Draw samples of size 10
  sample_means_10 = replicate(1000, mean(sample(data$WallThickness, 10, replace = TRUE)))
  cat("Sample mean for size 10:", mean(sample_means_10), "\n")

  # (b) Draw samples of size 50, 500, 9000
  sample_sizes = c(50, 500, 9000)
  for (n in sample_sizes) {
    sample_means = replicate(1000, mean(sample(data$WallThickness, n, replace = TRUE)))
    cat("Sample mean for size", n, ":", mean(sample_means), "\n")
  }
  ```

## 2. The following table gives information on ages and cholesterol levels for a random sample of 10 men
| Age         | 58  | 69  | 43  | 39  | 63  | 52  | 47  | 31  | 74  | 36  |
| ----------- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Cholesterol | 189 | 235 | 193 | 177 | 154 | 191 | 213 | 165 | 198 | 181 |

Plot the scatter diagram and a regression line that will enable us to predict Cholesterol level on age. Further, estimate the cholesterol level of a 60 year-old man.
  ```R
  age = c(58, 69, 43, 39, 63, 52, 47, 31, 74, 36)
  cholesterol = c(189, 235, 193, 177, 154, 191, 213, 165, 198, 181)

  model = lm(cholesterol ~ age)
  plot(age, cholesterol, pch = 16, col = "blue", xlab = "Age", ylab = "Cholesterol", main = "Cholesterol vs Age")
  abline(model, col = "red", lwd = 2)

  cat("Predicted cholesterol for age 60:", predict(model, newdata = data.frame(age = 60)), "\n")
  ```

## 3. A research methodology course has recently been added to the PhD curriculum at the Thapar Institute of Engineering and Technology, Patiala. To evaluate its effectiveness, students take a test on formulating research problems and writing research papers both before and after completing the course. Below are the marks for a random sample of ten students:

| Before the test | 145 | 173 | 158 | 141 | 167 | 159 | 154 | 167 | 145 | 153 |
| --------------- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| After the test  | 155 | 167 | 156 | 149 | 168 | 162 | 158 | 169 | 157 | 161 |

Assume that the differences between the pre-course and post-course test scores are normally distributed, and a high score on the test indicates a strong level of assertiveness. Do the collected data, at 5% level of significance, provide enough evidence to conclude that research scholars become more assertive after completing the course?
  ```R
  before = c(145, 173, 158, 141, 167, 159, 154, 167, 145, 153)
  after = c(155, 167, 156, 149, 168, 162, 158, 169, 157, 161)
  res = t.test(after - before, alternative = "greater")

  print(res)
  ```
