import os
from glob import glob
from setuptools import find_packages, setup

package_name = 'arith'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', glob(os.path.join('launch', '*.launch.py'))),
        ('share/' + package_name + '/param', glob(os.path.join('param', '*.yaml')))    
        ],

    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='kimjaehwan',
    maintainer_email='krcw3789@gmail.com',
    description='arith demo',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'argument = arith.argument:main',
            'calculater = arith.calculater:main'
        ],
    },
)
