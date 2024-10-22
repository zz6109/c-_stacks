from setuptools import find_packages, setup

package_name = 'homework'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='kimjaehwan',
    maintainer_email='krcw3789@gmail.com',
    description='homework demo',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "mpub = homework.mpub:main",
            "mtpub = homework.mtpub:main",
            "msub = homework.msub:main",
            "msub2 = homework.msub2:main",
            "mtsub = homework.mtsub:main"
            ],
    },
)
