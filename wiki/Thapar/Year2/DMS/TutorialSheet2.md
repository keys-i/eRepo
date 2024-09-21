# Tutorial Sheet 2

## Q1. Let 𝑃(𝑥), 𝑄(𝑥), 𝑅(𝑥), and 𝑆(𝑥) be the statements “𝑥 is a duck,” “𝑥 is one of my poultry,” “𝑥 is an officer,” and “𝑥 is willing to waltz,” respectively. Express each of these statements using quantifiers; logical connectives; and \( 𝑃(𝑥) \), \( 𝑄(𝑥) \), \( 𝑅(𝑥) \), and \( 𝑆(𝑥) \).
> a. No ducks are willing to waltz.<br>
> b. No officers ever decline to waltz.<br>
> c. All my poultry are ducks.<br>
> d. My poultry are not officers.<br>
> e. Does (d) follow from (a), (b), and (c)? If not, is there a correct conclusion?

Given:<br>
- \( P(x) \): "x is a duck"<br>
- \( Q(x) \): "x is one of my poultry"<br>
- \( R(x) \): "x is an officer"<br>
- \( S(x) \): "x is willing to waltz"

**a. No ducks are willing to waltz.**<br>
This translates: "For all x, if x is a duck, then x is not willing to waltz."
$$ \forall x(P(x) \rightarrow \neg S(x)) $$

**b. No officers ever decline to waltz.**<br>
This translates: "For all x, if x is an officer, then x is willing to waltz"
$$ \forall x(R(x) \rightarrow S(x)) $$

**c. All my poultry are ducks.**<br>
This translates: "For all x, if x is one of my poultry, then x is a duck."
$$ \forall x(Q(x) \rightarrow P(x)) $$

**d. My poultry are not officers.**<br>
This translates: "For all x, if x is one of my poultry, then x is not an officer."
$$ \forall x(Q(x) \rightarrow \neg R(x)) $$

**e. Does (d) follow from (a), (b), and (c)? If not, is there a correct conclusion?**<br>
Let's analyze:<br>
From (a): &nbsp;&nbsp;&nbsp; \( \forall x(P(x) \rightarrow \neg S(x)) \) (no ducks waltz).<br>
From (b): &nbsp;&nbsp;&nbsp; \( \forall x(R(x) \rightarrow S(x)) \) (all officers waltz).<br>
From (c): &nbsp;&nbsp;&nbsp; \( \forall x(Q(x) \rightarrow P(x)) \) (all poultry are ducks)<br><br>
We want to see if (d) \( \forall x(Q(x) \rightarrow \neg R(x)) \) follows logically.<br><br>
If all poultry are ducks _(from (c))_, and no ducks waltz _(from (a))_, then none of the poultry waltz.
However, if all officers waltz _(from (b))_, and the poultry do not waltz, this implies that no poultry
are officers _(because if they were officers, they would have to waltz, which contradicts (a))_.<br><br>
Thus, _(d)_ does follow from _(a)_, _(b)_, and _(c)_.

---

## Q2. Let 𝑃(𝑥), 𝑄(𝑥), and 𝑅(𝑥) be the statements “𝑥 is a professor,” “𝑥 is ignorant,” and “𝑥 is vain,”  respectively. Express each of these statements using quantifiers; logical connectives; and \( 𝑃(𝑥) \), \( 𝑄(𝑥) \), and \( 𝑅(𝑥) \), where the domain consists of all people.
a. No professors are ignorant.
b. All ignorant people are vain.
c. No professors are vain.
d. Does (c) follow from (a) and (b)? Explain.

---

## Q3. Use rules of inference to show that the hypotheses “If it does not rain or if it is not foggy,
then the sailing race will be held and the lifesaving demonstration will go on,” “If the sailing
race is held, then the trop hy will be awarded,” and “The trophy was not awarded” imply the
conclusion “It rained.”

---

## Q4. Consider
Premises: If Claghorn has wide support, then he'll be asked to run for the senate. If Claghorn
yells "Eureka" in Iowa, he will not be asked to run for the senate. Claghorn yells "Eureka" in
Iowa.
Conclusion: Claghorn does not have wide support.
Determine whether the conclusion follows logically from the premises. Explain by
representing the statements symbolically and using rules of inference.

---
## Q5. Consider the following open propositions over the universe 𝑈 = { −4, −2, 0, 1, 3, 5, 6, 8, 10}
𝑃(𝑥): 𝑥 ≥ 4
𝑄(𝑥): 𝑥2 = 25
𝑅(𝑥): 𝑠 is a multiple of 2
Find the truth values of
a. 𝑃(𝑥) ⋀ 𝑅(𝑥)
b. [~𝑄(𝑥)] ⋀ 𝑃(𝑥)

---
## Q6. Express each of these sentences into logical expression using predicates, quantifiers, and logical connectives.
a. No one is perfect.
b. Not everyone is perfect.
c. All your friends are perfect.
d. At least one of your friends is perfect
e. Everyone is your friend and is perfect.
f. Not everybody is your friend or someone is not perfect.
g. At least one mail message, among the nonempty set of messages, can be saved if there
is a disk with more than 10 kilobytes of free space.
h. Whenever there is an active alert , all queued messages are transmitted.
i. The diagnostic monitor tracks the status of all systems except the main console.
j. Each participant on the conference call whom the host

---
## Q7. Let 𝐷𝑥 = 𝑁 and 𝐷𝑦 = 𝑁0. Define 𝑃(𝑥, 𝑦) as “𝑥 divides 𝑦".
Find the truth values along with proper reasons for the following quantified predicates:
i. ∀𝑥 𝑃(𝑥, 0)
ii. ∀𝑥 𝑃(𝑥, 𝑥)
iii. ∀𝑦 ∃𝑥 𝑃(𝑥, 𝑦)
iv. ∃𝑦 ∀𝑥 𝑃(𝑥, 𝑦)
v. ∀𝑥 ∀𝑦 [(𝑃(𝑥, 𝑦) ⋀𝑃(𝑦, 𝑥)) → (𝑥 = 𝑦)]
vi. ∀𝑥 ∀𝑦 ∀𝑥 [(𝑃(𝑥, 𝑦) ⋀𝑃(𝑦, 𝑥)) → 𝑃(𝑥, 𝑧)]

---
## Q8. Identify the error or errors in this argument that supposedly shows that if ∀𝑥 (𝑃(𝑥) ∨ 𝑄(𝑥)) is
true then ∀𝑥 𝑃(𝑥) ⋁ ∀𝑥 𝑄(𝑥) is true.
a. ∀x(P(x) ∨ Q(x)) Premise
b. P(c) ∨ Q(c) Universal instantiation from (1)
c. P(c) Simplification from (2)
d. ∀xP(x) Universal generalization from (3)
e. Q(c) Simplification from (2)
f. ∀xQ(x) Universal generalization from (5)
g. ∀x(P(x) ∨ ∀xQ(x)) Conjunction from (4) and (6)

---
## Q9. Let \( k \) be a positive integer. Show that \( 1^k + 2^k + 3^k + \dots + n^k \) is \( O(n^{k+1}) \).
**Step 1: Expressing the Sum**
The Sum \( S(n) \) can be written as:
$$ S(n) = \sum_{i=1}^{n} i^k = 1^k + 2^k + 3^k + \dots + n^k $$
We want to show this sum grows asymptotically as \( O(n^{k+1}) \).
<br>
**Step 2: Estimating the Sum**
To estimate the \( S(n) \), we can compare it with an integral. The function \( f(x) = x^k \) increases as x increases, so:
$$ \int_{1}^{n} x^k dx \hspace{0.2 cm} and \int_{0}^{n} x^k dx $$
will provide good bounds for the sum.<br>
**1. Lower bound:**
$$ \int_{1}^{n} x^k dx = \frac{n^{k+1}}{k+1} - \frac{1^{k+1}}{k+1} = \frac{n^{k+1}}{k+1} - \frac{1}{k+1} $$

**2. Upper bound:**
$$ \int_{0}^{n} x^k dx = \frac{n^{k+1}}{k+1} $$

Thus, the sum \( S(n) \) is squeezed between two expressions that are propotional to \( n^{k+1} \)

**Step 3: Asymptotic Growth**
Since the sum \( S(n) \) is bounded by integrals that are both propotional to \( n^{k+1}\), we conclude that \( S(n) \)
grows asymptotically like n^{k+1}. More formally:
$$ S(n) = O(n^{k+1}) $$

---

## Q10. Prove that if n is an integer and 3n + 2 is even, then n is even using
a. proof by contraposition.<br>
b. proof by contradiction.

#### a. Proof by Contraposition
To prove that if \(3n+2\) is even, then \( n \) is even, we use proof by contraposition.
In this method, we prove the contrapositive of the given statement:
> If \( n \) is odd, then \(3n+2\) is odd.

**Proof:**<br>
1. Assume \( n \) is odd. By definition of odd integers, we can write \( n=2k+1 \), where \( k \) is an integer.<br>
2. Now, consider \( 3n+2 \):<br>
$$ 3n+2 = 3 (2k + 1) + 2 = 6k + 3 + 2 = 6k + 5 $$
&nbsp;&nbsp;&nbsp;&nbsp; Since \( 6k + 5 = 2(3k+2) + 1 \), this expression is odd _(because it is of the form \( 2m+1 \))_ <br>
&nbsp;&nbsp;&nbsp;&nbsp; for some integer \( m \).<br>
3. Thus, if \( n \) is odd, \( 3n+2 \) is odd, which proves the contrapositive.

Since the contrapositive is true, the original statement is also true: If \( 3n+2 \) is even, then \( n \) is even.

#### b. Proof by Contradiction
To prove that if \(3n+2\) is even, then \( n \) is even, we use proof by contradiction.
we assume the opposite of what we want to prove and show that it leads to a contradiction.

**Proof:**<br>
1. Assume \( 3n+2 \) is even but n is odd.<br>
2. Since n is odd, we can write \( n = 2k+1 \) for some integer \( k \).<br>
3. Substitute \( n = 2k+1 \) into the expression \( 3n+2 \):
$$ 3n+2 = 3 (2k + 1) + 2 = 6k + 3 + 2 = 6k + 5 $$
&nbsp;&nbsp;&nbsp;&nbsp; As shown earlier that \( 6k + 5 \)<br>
4. This contradicts our assumption that \( 3n+2 \) is even.<br>
5. Therefore, our assumption that \( n \) is odd must be false. Hence, \( n \) must be even.<br>
Thus, by contradiciton, if \( 3n+2 \) is even, \( n \) is even.

---

## Q11. Proof by contrapositive that for every real number 𝑥 𝜖 [0, 𝜋/2], we have sin 𝑥 + cos 𝑥 ≥ 1.

---

## Q12. What is wrong with the following proof? Explain your answer with a valid explanation.
Prove that the statement \( \sqrt{2} + \sqrt{6} < \sqrt{15} \) is true.<br>
“Proof”:<br>
Step 1. \( \sqrt{2} + \sqrt{6} < \sqrt{15} \)<br>
Step 2. \( (\sqrt{2} + √6)^2 < 15 \)<br>
Step 3. \( \sqrt{8} + 2\sqrt{12} < 15 \)<br>
Step 4. \( 2\sqrt{12} < 7 \)<br>
Step 5. \( 48 < 49 \)

---

## Q13. Derive the formula for the following expression:
$$ \frac{1}{2} + \frac{1}{4} + \frac{1}{8} + \cdot\cdot\cdot + \frac{1}{2^n} $$
Also prove the validity of your formula using mathematical induction.

#### Derivation of the formula
