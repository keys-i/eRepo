# Tutorial Sheet 2

## Q1. Let 𝑃(𝑥), 𝑄(𝑥), 𝑅(𝑥), and 𝑆(𝑥) be the statements “𝑥 is a duck,” “𝑥 is one of my poultry,” “𝑥 is an officer,” and “𝑥 is willing to waltz,” respectively. Express each of these statements using quantifiers; logical connectives; and \( 𝑃(𝑥) \), \( 𝑄(𝑥) \), \( 𝑅(𝑥) \), and \( 𝑆(𝑥) \).
a. No ducks are willing to waltz.<br>
b. No officers ever decline to waltz.<br>
c. All my poultry are ducks.<br>
d. My poultry are not officers.<br>
e. Does (d) follow from (a), (b), and (c)? If not, is there a correct conclusion?
### **Solution:**
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
a. No professors are ignorant.<br>
b. All ignorant people are vain.<br>
c. No professors are vain.<br>
d. Does (c) follow from (a) and (b)? Explain.<br>

### **Solution:**
Given:<br>
- \( P(x) \): "x is a professor"<br>
- \( Q(x) \): "x is ignorant<br>
- \( R(x) \): "x is x is vain"<br>

**a. No professors are ignorant.**<br>
This translates: "For all x, if x is a professor, then x is not ignorant."
$$ \forall x(P(x) \rightarrow \neg Q(x)) $$

**b. All ignorant people are vain.**<br>
This translates: "For all x, if x is ignorant, then x is vain"
$$ \forall x(Q(x) \rightarrow R(x)) $$

**c. No professors are vain.**<br>
This translates: "For all x, if x is a professor, then x is not vain."
$$ \forall x(P(x) \rightarrow \neg R(x)) $$

**d. Does (c) follow from (a) and (b)? Explain.**<br>
Let's analyze:<br>
From (a): &nbsp;&nbsp;&nbsp; \( \forall x(P(x) \rightarrow \neg Q(x)) \) (no professors are ignorant).<br>
From (b): &nbsp;&nbsp;&nbsp; \( \forall x(Q(x) \rightarrow R(x)) \) (ignorant people are vain).<br>

We want to see if (c) \( \forall x(P(x) \rightarrow \neg R(x)) \) follows logically.<br><br>
If no professors are ignorant _(from (a))_, and only ignorant people are vain _(from (b))_, we can infer that no professors are vain.<br>
Here's the reasoning:<br>
- From (a), if someone is a professor, they’re not ignorant (\( \neg Q(x) \)).<br>
- From (b), we know only ignorant people are vain, so if a professor isn’t ignorant, they can’t be vain.

Thus, _(c)_ does follow from _(a)_, and _(b)_.

---

## Q3. Use rules of inference to show that the hypotheses “If it does not rain or if it is not foggy, then the sailing race will be held and the lifesaving demonstration will go on,” “If the sailing race is held, then the trop hy will be awarded,” and “The trophy was not awarded” imply the conclusion “It rained.”
### **Solution:**
Let's break down the problem step by step using the rules of inference to show that the given hypotheses imply the conclusion "It rained."

#### Step 1: Label the statements
- Let **R** represent "It rains."
- Let **F** represent "It is foggy."
- Let **S** represent "The sailing race is held."
- Let **L** represent "The lifesaving demonstration will go on."
- Let **T** represent "The trophy is awarded."

#### Step 2: Translate the hypotheses into logical statements
1. "If it does not rain or if it is not foggy, then the sailing race will be held and the lifesaving demonstration will go on."
   This can be written as:
   \( (\neg R \lor \neg F) \rightarrow (S \land L) \)

2. "If the sailing race is held, then the trophy will be awarded."
   This is:
   \( S \rightarrow T \)

3. "The trophy was not awarded."
   This is:
   \( \neg T \)

#### Step 3: Use the rules of inference
We are given the goal of proving that it rained, i.e., proving \( R \).

1. From statement 3, we know that \( \neg T \) (the trophy was not awarded).

2. Using **Modus Tollens** on statement 2 (since \( S \rightarrow T \) and \( \neg T \)), we can conclude:
   \[
   \neg S
   \]
   (The sailing race was not held.)

3. Now, use **Modus Tollens** again on statement 1, \( (\neg R \lor \neg F) \rightarrow (S \land L) \), combined with \( \neg S \). Since the sailing race was not held (\( \neg S \)), it means that \( \neg R \lor \neg F \) must be false for the implication to hold true. For \( \neg R \lor \neg F \) to be false, both \( \neg R \) and \( \neg F \) must be false. This means:
   \[
   R \land F
   \]
   (It rained, and it was foggy.)

#### Conclusion:
From this reasoning, we have shown that the hypotheses logically imply that **it rained**. So the conclusion "It rained" (\( R \)) follows from the given premises using the rules of inference.

---

## Q4. Consider
**Premises:** If Claghorn has wide support, then he'll be asked to run for the senate. If Claghorn
yells "Eureka" in Iowa, he will not be asked to run for the senate. Claghorn yells "Eureka" in
Iowa.<br>
**Conclusion:** Claghorn does not have wide support.<br><br>
Determine whether the conclusion follows logically from the premises. Explain by
representing the statements symbolically and using rules of inference.

### **Solution:**
Let's break this down step by step to see if the conclusion logically follows from the premises. We'll represent the statements symbolically and apply the rules of inference to make everything clear.

#### Step 1: Define the statements
- Let **W** represent "Claghorn has wide support."
- Let **S** represent "Claghorn will be asked to run for the senate."
- Let **E** represent "Claghorn yells 'Eureka' in Iowa."

#### Step 2: Translate the premises into symbolic form
1. "If Claghorn has wide support, then he'll be asked to run for the senate."
   Symbolically:
   \( W \rightarrow S \)

2. "If Claghorn yells 'Eureka' in Iowa, he will not be asked to run for the senate."
   Symbolically:
   \( E \rightarrow \neg S \)

3. "Claghorn yells 'Eureka' in Iowa."
   Symbolically:
   \( E \)

#### Step 3: Apply the rules of inference
We need to determine if the conclusion "Claghorn does not have wide support" (i.e., \( \neg W \)) follows logically from these premises.

1. From premise 3, we know that \( E \) is true (Claghorn yells "Eureka" in Iowa).

2. Using **Modus Ponens** on premise 2 and \( E \), we can conclude \( \neg S \) (Claghorn will not be asked to run for the senate).

3. Now, look at premise 1: \( W \rightarrow S \) (If Claghorn has wide support, then he'll be asked to run for the senate). We know that \( S \) is false because we just concluded \( \neg S \).

4. Using **Modus Tollens** on premise 1 and \( \neg S \), we can conclude \( \neg W \) (Claghorn does not have wide support).

#### Conclusion:
Yes, the conclusion "Claghorn does not have wide support" (\( \neg W \)) follows logically from the premises. By representing the statements symbolically and using the rules of inference (specifically Modus Ponens and Modus Tollens), we’ve shown that the conclusion is valid.

---

## Q5. Consider the following open propositions over the universe 𝑈 = { −4, −2, 0, 1, 3, 5, 6, 8, 10}
\( 𝑃(𝑥): 𝑥 ≥ 4 \)<br>
\( 𝑄(𝑥): 𝑥2 = 25 \)<br>
\( 𝑅(𝑥): 𝑠 \) is a multiple of \( 2 \)<br>
Find the truth values of<br>
a. \( 𝑃(𝑥) \bigwedge 𝑅(𝑥)\)<br>
b. \( [\neg𝑄(𝑥)] \bigwedge 𝑃(𝑥) \)
Let's work through this problem step by step, starting with the truth values for the given propositions.

### **Solution:**
#### Universe \( U = \{ -4, -2, 0, 1, 3, 5, 6, 8, 10 \} \)
We are given three propositions:
- \( P(x): x \geq 4 \)
- \( Q(x): x^2 = 25 \)
- \( R(x): x \) is a multiple of 2

#### a. \( P(x) \land R(x) \)
We need to find the truth value of \( P(x) \land R(x) \), which means \( x \geq 4 \) and \( x \) is a multiple of 2.

Go through each element in \( U \):
- \( x = -4 \): \( P(x) \) is false (since \( -4 \not\geq 4 \)), so \( P(x) \land R(x) \) is false.
- \( x = -2 \): \( P(x) \) is false, so \( P(x) \land R(x) \) is false.
- \( x = 0 \): \( P(x) \) is false, so \( P(x) \land R(x) \) is false.
- \( x = 1 \): \( P(x) \) is false, so \( P(x) \land R(x) \) is false.
- \( x = 3 \): \( P(x) \) is false, so \( P(x) \land R(x) \) is false.
- \( x = 5 \): \( P(x) \) is true (since \( 5 \geq 4 \)), but \( R(x) \) is false (since 5 is not a multiple of 2), so \( P(x) \land R(x) \) is false.
- \( x = 6 \): \( P(x) \) is true and \( R(x) \) is true, so \( P(x) \land R(x) \) is true.
- \( x = 8 \): \( P(x) \) is true and \( R(x) \) is true, so \( P(x) \land R(x) \) is true.
- \( x = 10 \): \( P(x) \) is true and \( R(x) \) is true, so \( P(x) \land R(x) \) is true.

**Truth values of \( P(x) \land R(x) \):**
True for \( x = 6, 8, 10 \).

#### b. \( \neg Q(x) \land P(x) \)
Now let's find the truth value of \( \neg Q(x) \land P(x) \), meaning \( x^2 \neq 25 \) and \( x \geq 4 \).

Check each element in \( U \):
- \( x = -4 \): \( Q(x) \) is false (since \( (-4)^2 \neq 25 \)), and \( P(x) \) is false, so \( \neg Q(x) \land P(x) \) is false.
- \( x = -2 \): \( Q(x) \) is false and \( P(x) \) is false, so \( \neg Q(x) \land P(x) \) is false.
- \( x = 0 \): \( Q(x) \) is false and \( P(x) \) is false, so \( \neg Q(x) \land P(x) \) is false.
- \( x = 1 \): \( Q(x) \) is false and \( P(x) \) is false, so \( \neg Q(x) \land P(x) \) is false.
- \( x = 3 \): \( Q(x) \) is false and \( P(x) \) is false, so \( \neg Q(x) \land P(x) \) is false.
- \( x = 5 \): \( Q(x) \) is true (since \( 5^2 = 25 \)), so \( \neg Q(x) \land P(x) \) is false.
- \( x = 6 \): \( Q(x) \) is false and \( P(x) \) is true, so \( \neg Q(x) \land P(x) \) is true.
- \( x = 8 \): \( Q(x) \) is false and \( P(x) \) is true, so \( \neg Q(x) \land P(x) \) is true.
- \( x = 10 \): \( Q(x) \) is false and \( P(x) \) is true, so \( \neg Q(x) \land P(x) \) is true.

**Truth values of \( \neg Q(x) \land P(x) \):**
True for \( x = 6, 8, 10 \).

---

## Q6. Express each of these sentences into logical expression using predicates, quantifiers, and logical connectives.
a. No one is perfect.<br>
b. Not everyone is perfect.<br>
c. All your friends are perfect.<br>
d. At least one of your friends is perfect.<br>
e. Everyone is your friend and is perfect.<br>
f. Not everybody is your friend or someone is not perfect.<br>
g. At least one mail message, among the nonempty set of messages, can be saved if there.<br>
is a disk with more than 10 kilobytes of free space.<br>
h. Whenever there is an active alert , all queued messages are transmitted.<br>
i. The diagnostic monitor tracks the status of all systems except the main console.<br>
j. Each participant on the conference call whom the host.<br>
### **Solution:**
Let’s turn these sentences into logical expressions using predicates, quantifiers, and logical connectives, while keeping it clear and understandable.

#### a. No one is perfect.
Let \( P(x) \) represent “\( x \) is perfect,” and the domain be all people. This can be written as:
\[
\forall x \, \neg P(x)
\]
This means: "For all \( x \), \( x \) is not perfect."

#### b. Not everyone is perfect.
Again, using \( P(x) \) to represent “\( x \) is perfect,” this can be written as:
\[
\neg \forall x \, P(x)
\]
Or equivalently:
\[
\exists x \, \neg P(x)
\]
This means: "There exists at least one person who is not perfect."

#### c. All your friends are perfect.
Let \( F(x) \) represent “\( x \) is your friend,” and \( P(x) \) represent “\( x \) is perfect.” This can be written as:
\[
\forall x \, (F(x) \rightarrow P(x))
\]
This means: "For every \( x \), if \( x \) is your friend, then \( x \) is perfect."

#### d. At least one of your friends is perfect.
This can be written as:
\[
\exists x \, (F(x) \land P(x))
\]
This means: "There exists at least one \( x \) such that \( x \) is your friend and \( x \) is perfect."

#### e. Everyone is your friend and is perfect.
This can be written as:
\[
\forall x \, (F(x) \land P(x))
\]
This means: "For all \( x \), \( x \) is your friend and \( x \) is perfect."

#### f. Not everybody is your friend or someone is not perfect.
This can be written as:
\[
\neg \forall x \, F(x) \lor \exists x \, \neg P(x)
\]
This means: "Not everyone is your friend, or there is at least one person who is not perfect."

#### g. At least one mail message, among the nonempty set of messages, can be saved if there is a disk with more than 10 kilobytes of free space.
Let \( M(x) \) represent “\( x \) is a mail message,” \( S(x) \) represent “\( x \) can be saved,” and \( D(y) \) represent “Disk \( y \) has more than 10 kilobytes of free space.” This can be written as:
\[
\exists x \, (M(x) \land \exists y \, D(y) \rightarrow S(x))
\]
This means: "There exists at least one mail message that can be saved if there is a disk with more than 10 kilobytes of free space."

#### h. Whenever there is an active alert, all queued messages are transmitted.
Let \( A \) represent “There is an active alert,” and \( Q(x) \) represent “\( x \) is a queued message,” and \( T(x) \) represent “\( x \) is transmitted.” This can be written as:
\[
A \rightarrow \forall x \, (Q(x) \rightarrow T(x))
\]
This means: "If there is an active alert, then for all \( x \), if \( x \) is a queued message, then \( x \) is transmitted."

#### i. The diagnostic monitor tracks the status of all systems except the main console.
Let \( D \) represent “The diagnostic monitor tracks the status,” \( S(x) \) represent “\( x \) is a system,” and \( M \) represent “the main console.” This can be written as:
\[
\forall x \, (S(x) \land x \neq M \rightarrow D(x))
\]
This means: "For all systems \( x \), if \( x \) is not the main console, the diagnostic monitor tracks \( x \)."

#### j. Each participant on the conference call whom the host invites can speak.
Let \( P(x) \) represent “\( x \) is a participant,” \( H(x) \) represent “The host invites \( x \),” and \( S(x) \) represent “\( x \) can speak.” This can be written as:
\[
\forall x \, (P(x) \land H(x) \rightarrow S(x))
\]
This means: "For every participant \( x \), if the host invites \( x \), then \( x \) can speak."

These translations express the meaning of each statement using logical symbols in a clear way, perfect for reasoning with predicates, quantifiers, and connectives.

---

## Q7. Let \( 𝐷_{𝑥} = 𝑁 \) and \( 𝐷_{𝑦} = 𝑁^0 \). Define \( 𝑃(𝑥, 𝑦) \) as “𝑥 divides 𝑦".
Find the truth values along with proper reasons for the following quantified predicates:<br>
i. \( \forall 𝑥 \hspace{0.2cm} 𝑃(𝑥, 0) \)<br>
ii. \( \forall 𝑥 \hspace{0.2cm} 𝑃(𝑥, 𝑥) \)<br>
iii. \( \forall 𝑦 \hspace{0.2cm} \exists 𝑥 \hspace{0.2cm} 𝑃(𝑥, 𝑦) \)<br>
iv. \( \exists 𝑦 \hspace{0.2cm} \forall 𝑥 \hspace{0.2cm} 𝑃(𝑥, 𝑦) \)<br>
v. \( \forall 𝑥 \hspace{0.2cm} \forall 𝑦 \hspace{0.2cm} [(𝑃(𝑥, 𝑦) \bigwedge 𝑃(𝑦, 𝑥)) \rightarrow (𝑥 = 𝑦)] \)<br>
vi. \( \forall 𝑥 \hspace{0.2cm} \forall 𝑦 \hspace{0.2cm} \forall 𝑥 \hspace{0.2cm} [(𝑃(𝑥, 𝑦) \bigwedge 𝑃(𝑦, 𝑥)) \rightarrow 𝑃(𝑥, 𝑧)] \)

### **Solution:**
Let’s evaluate the truth values of these quantified predicates step by step using clear reasoning.

#### i. \( \forall x \, P(x, 0) \)
This is asking whether every \( x \) divides 0. By definition, every integer divides 0 because \( 0 = x \times 0 \) for any \( x \), so this statement is **true**.

**Reason**: For all integers \( x \), \( x \) divides 0, since \( 0 \div x = 0 \).

#### ii. \( \forall x \, P(x, x) \)
This is asking whether every \( x \) divides itself. Clearly, any integer divides itself because \( x \div x = 1 \). Therefore, this statement is **true**.

**Reason**: For any \( x \), \( x \div x = 1 \), so every \( x \) divides itself.

#### iii. \( \forall y \, \exists x \, P(x, y) \)
This is asking if, for every \( y \), there exists an \( x \) such that \( x \) divides \( y \). This is **true** because for every integer \( y \), \( x = 1 \) divides \( y \).

**Reason**: \( x = 1 \) divides every integer \( y \), so there exists at least one \( x \) (which is 1) that divides any \( y \).

#### iv. \( \exists y \, \forall x \, P(x, y) \)
This asks if there is some \( y \) such that all \( x \) divide \( y \). This is **true**, since 0 is such a \( y \) — all integers divide 0.

**Reason**: \( y = 0 \) works because, as established earlier, every integer \( x \) divides 0.

#### v. \( \forall x \, \forall y \, [(P(x, y) \land P(y, x)) \rightarrow (x = y)] \)
This is asking if \( x \) divides \( y \) and \( y \) divides \( x \), does it imply \( x = y \)? This is **true**, because if two integers divide each other, they must be equal (e.g., if 4 divides 4, then 4 and 4 are the same).

**Reason**: If \( x \) divides \( y \) and \( y \) divides \( x \), it’s only possible when \( x = y \).

#### vi. \( \forall x \, \forall y \, \forall z \, [(P(x, y) \land P(y, z)) \rightarrow P(x, z)] \)
This is the transitive property of divisibility: if \( x \) divides \( y \), and \( y \) divides \( z \), then \( x \) must divide \( z \). This is **true** because divisibility is transitive.

**Reason**: If \( x \) divides \( y \), and \( y \) divides \( z \), then \( x \) divides \( z \). For example, if 2 divides 4, and 4 divides 8, then 2 divides 8.

These evaluations show how each logical expression holds based on the properties of divisibility within the set of integers.

---
## Q8. Identify the error or errors in this argument that supposedly shows that if \( \forall 𝑥 (𝑃(𝑥) \bigvee 𝑄(𝑥)) \) is true then \( \forall 𝑥 𝑃(𝑥) \bigvee \forall 𝑥 𝑄(𝑥) \) is true.
a. \( \forall x \hspace{0.2cm} (P(x) \bigvee Q(x)) \) <span style="float: right;">Premise</span><br>
b. \( P(c) \bigvee Q(c) \) <span style="float: right;">Universal instantiation from (a)</span><br>
c. \( P(c) \) <span style="float: right;">Simplification from (b)</span><br>
d. \( \forall x \hspace{0.2cm} P(x) \) <span style="float: right;">Universal generalization from (c)</span><br>
e. \( Q(c) \) <span style="float: right;">Simplification from (b)</span><br>
f. \( \forall x \hspace{0.2cm} Q(x) \) <span style="float: right;">Universal generalization from (e)</span><br>
g. \( \forall x \hspace{0.2cm} (P(x) \bigvee Q(x)) \) <span style="float: right;">Conjunction from (d) and (f)</span>

### **Solution:**
To understand why this argument doesn't work, let's break it down and identify the errors step by step:

1. **Premise**:<br> \( \forall x \, (P(x) \vee Q(x)) \) states that for every \(x\), either \(P(x)\) or \(Q(x)\) is true. So far, everything seems fine.

2. **Universal Instantiation**:<br> From the premise, we instantiate with a specific \(c\), so we get \( P(c) \vee Q(c) \). This also holds since it's derived from the original universal statement.

3. **Simplification**:<br> Here's where things start to get tricky. The argument jumps to assuming \(P(c)\) (and later \(Q(c)\)) without justification. But all we know is that either \(P(c)\) is true, or \(Q(c)\) is true. You can't claim one or the other without further information. So, the error here is in assuming one part of the disjunction without ruling out the other.

4. **Universal Generalization**:<br> Moving from \(P(c)\) to \( \forall x \, P(x) \) is a mistake. Just because something holds for one instance \(c\), you can't generalize it to all \(x\). This step violates the rules of universal generalization, which requires showing that \(P(x)\) holds for all \(x\), not just one case.

5. **Conjunction**:<br> Finally, the argument combines \( \forall x \, P(x) \) and \( \forall x \, Q(x) \), but neither of these are valid conclusions from the earlier steps. So, the whole argument falls apart here.

#### In summary:
The errors are in assuming individual parts of a disjunction and incorrectly generalizing from specific instances to universal statements. This mix-up leads to the false conclusion that \( \forall x P(x) \vee \forall x Q(x) \) follows from \( \forall x (P(x) \vee Q(x)) \).

---
## Q9. Let \( k \) be a positive integer. Show that \( 1^k + 2^k + 3^k + \dots + n^k \) is \( O(n^{k+1}) \).
### **Solution:**
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
### **Solution:**
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
### **Solution:**
To prove that for any \( x \in [0, \pi/2] \), \( \sin x + \cos x \geq 1 \) using the contrapositive, let's take a more straightforward approach.

#### Original statement:
For every real number \( x \in [0, \pi/2] \), \( \sin x + \cos x \geq 1 \).

#### Contrapositive:
The contrapositive of this statement is:
**If \( \sin x + \cos x < 1 \), then \( x \notin [0, \pi/2] \).**

Now, let’s prove this.

##### Step 1: Start by assuming the contrapositive
Assume that \( \sin x + \cos x < 1 \). What we need to show is that this implies \( x \) cannot be in the interval \( [0, \pi/2] \).

##### Step 2: Examine the sum of sine and cosine
We know that in the interval \( [0, \pi/2] \):
- At \( x = 0 \), \( \sin 0 = 0 \) and \( \cos 0 = 1 \), so \( \sin 0 + \cos 0 = 1 \).
- At \( x = \pi/2 \), \( \sin \pi/2 = 1 \) and \( \cos \pi/2 = 0 \), so \( \sin \pi/2 + \cos \pi/2 = 1 \).

For any \( x \) in between, the sum \( \sin x + \cos x \) is always at least 1. This makes sense because both sine and cosine are positive within this interval, and their squares sum to 1 (thanks to the Pythagorean identity: \( \sin^2 x + \cos^2 x = 1 \)).

##### Step 3: Conclusion
If \( \sin x + \cos x < 1 \), then \( x \) can't be in \( [0, \pi/2] \), because we've shown that within this range, the sum of sine and cosine is always at least 1. So, \( x \) must be outside of \( [0, \pi/2] \).

By proving the contrapositive, we’ve effectively shown that for every \( x \in [0, \pi/2] \), \( \sin x + \cos x \geq 1 \), which is what we set out to prove.

---

## Q12. What is wrong with the following proof? Explain your answer with a valid explanation.
Prove that the statement \( \sqrt{2} + \sqrt{6} < \sqrt{15} \) is true.<br>
“Proof”:<br>
Step 1. \( \sqrt{2} + \sqrt{6} < \sqrt{15} \)<br>
Step 2. \( (\sqrt{2} + √6)^2 < 15 \)<br>
Step 3. \( \sqrt{8} + 2\sqrt{12} < 15 \)<br>
Step 4. \( 2\sqrt{12} < 7 \)<br>
Step 5. \( 48 < 49 \)<br>

### **Solution:**
The error in the proof happens in Step 3, where there's a misunderstanding of how to handle squared terms. Let's break it down in a way that’s easy to follow:

1. **Step 1**: You're asked to prove \( \sqrt{2} + \sqrt{6} < \sqrt{15} \).

2. **Step 2**: Squaring both sides to simplify things is okay. So, the inequality becomes:
   \((\sqrt{2} + \sqrt{6})^2 < (\sqrt{15})^2\)
   Expanding the left side gives:
   \(2 + 6 + 2\sqrt{2 \times 6} = 8 + 2\sqrt{12}\)
   Now, the inequality is:
   \(8 + 2\sqrt{12} < 15\)

3. **Step 3**: Here's where the mistake happens. The proof wrongly changes \( 8 \) into \( \sqrt{8} \), which isn’t allowed. So, instead of \( \sqrt{8} + 2\sqrt{12} \), it should have stayed as \( 8 + 2\sqrt{12} \).

4. **Step 4**: From the correct form \( 8 + 2\sqrt{12} < 15 \), we can move the 8 over:
   \(2\sqrt{12} < 7\)
   Dividing both sides by 2 gives:
   \(\sqrt{12} < 3.5\)
   Squaring both sides results in:
   \(12 < 12.25\)
   Which is true, confirming the original statement.

So, the key issue is in Step 3, where the proof incorrectly simplifies \( 8 \) as \( \sqrt{8} \), leading to a wrong direction. Otherwise, the inequality holds true.

---

## Q13. Derive the formula for the following expression:
$$ \frac{1}{2} + \frac{1}{4} + \frac{1}{8} + \cdot\cdot\cdot + \frac{1}{2^n} $$
Also prove the validity of your formula using mathematical induction.

### **Solution:**
#### Derivation of the formula
$$ \frac{1}{2} + \frac{1}{4} + \frac{1}{8} + \cdot\cdot\cdot + \frac{1}{2^n} $$

This is a geometric series where the first term \( a=\frac{1}{2} \) and the common ratio \( r=\frac{1}{2} \).<br>
The sum of the first \( n \) terms of a geometric series is given by the formula:<br>
$$ S_{n} = a \frac{1-r^n}{1-r} $$
Substitute the values of \( a = \frac{1}{2} \) and \( r = \frac{1}{2} \) into the formula:<br>
$$ S_{n} = \frac{1}{2} \cdot \frac{1-(\frac{1}{2})^n}{1-\frac{1}{2}} = \frac{1}{2} \cdot \frac{1-\frac{1}{2^n}}{\frac{1}{2}} = 1-\frac{1}{2^n} $$
Thus, the formula for the sum of the series is:
$$ S_{n} = 1-\frac{1}{2^n} $$

#### Proof by Mathematical Induction
We will now prove the formula \( S_{n} = 1-\frac{1}{2^n} \) using mathematical induction.
##### Best Case (n=1):
When \( n=1 \), the sum of the series is:
$$ S_{1} = \frac{1}{2}$$
Using the formula for \( n = 1 \):
$$ S_{1} = 1-\frac{1}{2^1} = 1-\frac{1}{2} = \frac{1}{2}$$
Thus, the formula holds for \( n=1 \).

##### Inductive Step:
Assume the formula is true for \( n = k \), i.e.,
$$ S_{k} = 1 - \frac{1}{2^k} $$
We need to prove that the formula holds for \( n = k+1 \), i.e.,
$$ S_{k+1} = 1 - \frac{1}{2^{k+1}} $$
From the Assumption, the sum up to \( n = k \) is:
$$ S_{k} = 1 - \frac{1}{2^k} $$
To find \( S_{k+1} \), we add the next term \( \frac{1}{2^{k+1}} \) to \( S_{k} \):
$$ S_{k+1} = S_{k} + \frac{1}{2^{k+1}} = \left( 1 - \frac{1}{2^k} \right) + \frac{1}{2^{k+1}} $$
Simplifying the right-hand side:
$$ S_{k+1} = 1 - \frac{1}{2^k} + \frac{1}{2^{k+1}} = 1 - \frac{1}{2^k} \left( 1 - \frac{1}{2} \right) $$
$$ S_{k+1} = 1 - \frac{1}{2^k}\cdot \frac{1}{2} = 1 - \frac{1}{2^{k+1}} $$
Thus, the formula holds for \( n = k+1 \).

#### Conclusion:
By the principle of mathematical induction, the formula \( S_n = 1 - \frac{1}{2^n} \) is valid for all \( n \geq 1 \).
