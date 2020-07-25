const express = require('express')
const app = express()
const fs = require('fs');
const mongoose = require('mongoose');
mongoose.connect(process.env.MONGODB_URL || 'mongodb://localhost/atmosphere', {useNewUrlParser: true, useUnifiedTopology: true });
const db = mongoose.connection;
const Atmosphere = require('./models/atmosphereModel');
const routes = require('./routes')

const port = process.env.PORT || 3000
app.use(express.json()); 


//Get all atmospheric data
app.get('/atmosphere', routes.getAllAtmosphericData);

//Post atmospheric data
app.post('/atmosphere', routes.postAtmosphericData);

//Get the most recent atmospheric data
app.get('/atmosphere/recent', routes.getMostRecentAtmosphericData);



app.listen(port, () => console.log(`Atmosphere API at http://localhost:${port}`));
db.on('error', console.error.bind(console, 'connection error:'));
db.once('open', () => console.log("connected to DB"));