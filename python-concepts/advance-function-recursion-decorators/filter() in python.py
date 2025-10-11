# 1. filter() Function Kya Hai?
# filter() ek iterable se sirf wahi elements select karta hai jo condition satisfy karte hain.
# filter(function, iterable)
# ⚡ Important: filter() ek filter object (iterator) return karta hai, isko list/tuple me convert karna padta hai.

# 2. Examples
 
# Example 1 – Even Numbers (Named Function)
def evenNums(nums):
    return nums % 2 == 0

original_numsList = [1, 2, 3, 4, 5, 6]
even_numsList = filter(evenNums, original_numsList)
print(list(even_numsList))

# Example 2 – Even Numbers (Lambda Function)

original_numsList = [1, 2, 3, 4, 5, 6]
even_numsList = filter(lambda x: x % 2 == 0, original_numsList)
print(list(even_numsList))

# Example 3 – Filtering + Transforming (filter + map)
original_numsList = [1, 2, 3, 4, 5, 6]
even_numsList = filter(lambda x: x % 2 == 0, original_numsList)
double_even_numsList = map(lambda x: x * 2, even_numsList)

print(list(double_even_numsList))

# Example 4 – Filter Strings (Length > 5)


original_nameList = ["apple", "banana", "cherry", "kiwi", "grape"]
filtered_nameList = filter(lambda w : len(w) > 5, original_nameList)
print(list(filtered_nameList))

# Example 5 – Filter Falsy Values

original_values=  ["apple", "", None, "banana", 0, "cherry"]
truthy_value = filter(None, original_values)
print(list(truthy_value))