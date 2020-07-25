const mongoose = require('mongoose');


const atmosphereSchema = new mongoose.Schema({
    temperature: Number,
    humidity: Number
  },
  {
    timestamps: { createdAt: true, updatedAt: false },
    versionKey: false // Don't need version for my use.
  }
  
  );

  module.exports = Atmosphere = mongoose.model('Atmosphere', atmosphereSchema); 