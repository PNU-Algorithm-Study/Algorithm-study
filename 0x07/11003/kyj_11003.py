from PIL import Image

image = Image.open("../../../../Downloads/mouse.png").convert("RGBA")
pixels = image.load()

for y in range(image.height):
    for x in range(image.width):
        r, g, b, a = pixels[x, y]

        if r < 50 and g < 50 and b < 50 and a != 0:
            pixels[x, y] = (255, 255, 255, a)

image.save("output_image.png")
image.show()