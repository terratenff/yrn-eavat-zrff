# yrn-eavat-zrff

This is a desktop application that attempts to demonstrate simple, interactively easy-to-edit neural networks. They apply a genetic algorithm to train them in real-time. Qt framework is utilized, and Qt Creator is used as IDE.

The application revolves around a simple "shipyard" in 2D space. You control a ship with mouse clicks to move it around, while other smaller ships (called "subjects" in the application) attempt to meet one of few objectives. Their most common goal is to be as close to your ship as possible.

Subjects have neural networks of their own that control their movement. Their behaviour can be tailored with a variety of settings, the most notable options being input type, output type, neural network structure and activation functions. More details of these settings can be found during application runtime.

A collection of settings can be saved as a "scenario" for later use, potentially saving time from making the same settings manually. Examples of scenarios are situated in the folder "sample_scenarios".
