import matplotlib.pyplot as plt
import numpy as np 

H, fordiff, cendiff, rfordiff, rcendiff = np.loadtxt("datos.txt", unpack=True)
fig, ax = plt.subplots()
ax.loglog(H, fordiff, '--o')
ax.loglog(H, cendiff, '--o')
ax.loglog(H, rfordiff, '--o')
ax.loglog(H, rcendiff, '--o')
ax.set_title("percentual_diff")
ax.set_xlabel("H")
ax.set_ylabel("Percentual diff ")
plt.legend(["diff forward","diff central","diff forward Richardson","diff central Richardson"])
plt.show()
fig.savefig("percentual_diff.pdf",bbox_inches='tight')

