import torch
from torchvision.models import resnet18
from torchinfo import summary

model = resnet18(weights=None)
model.eval()

result = summary(
    model,
    input_size=(1, 3, 224, 224),
    col_names=["input_size", "output_size", "num_params", "mult_adds"],
    verbose=0
)

with open("codefest/cf01/profiling/resnet18_profile.txt", "w") as f:
    f.write(str(result))

print("Profile saved.")
