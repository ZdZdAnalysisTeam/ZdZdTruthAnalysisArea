#Tue Dec  6 15:08:01 2016"""Automatically generated. DO NOT EDIT please"""
from GaudiKernel.GaudiHandles import *
from GaudiKernel.Proxy.Configurable import *

class ZdZdPlottingAlg( ConfigurableAlgorithm ) :
  __slots__ = { 
    'OutputLevel' : 0, # int
    'Enable' : True, # bool
    'ErrorMax' : 1, # int
    'ErrorCounter' : 0, # int
    'AuditAlgorithms' : False, # bool
    'AuditInitialize' : False, # bool
    'AuditReinitialize' : False, # bool
    'AuditRestart' : False, # bool
    'AuditExecute' : False, # bool
    'AuditFinalize' : False, # bool
    'AuditBeginRun' : False, # bool
    'AuditEndRun' : False, # bool
    'AuditStart' : False, # bool
    'AuditStop' : False, # bool
    'MonitorService' : 'MonitorSvc', # str
    'RegisterForContextService' : False, # bool
    'EvtStore' : ServiceHandle('StoreGateSvc'), # GaudiHandle
    'DetStore' : ServiceHandle('StoreGateSvc/DetectorStore'), # GaudiHandle
    'UserStore' : ServiceHandle('UserDataSvc/UserDataSvc'), # GaudiHandle
    'THistSvc' : ServiceHandle('THistSvc/THistSvc'), # GaudiHandle
    'RootStreamName' : '/', # str
    'RootDirName' : '', # str
    'HistNamePrefix' : '', # str
    'HistNamePostfix' : '', # str
    'HistTitlePrefix' : '', # str
    'HistTitlePostfix' : '', # str
    'DebugEventNumber' : 0, # int
  }
  _propertyDocDct = { 
    'HistTitlePrefix' : """ The prefix for the histogram THx title """,
    'DetStore' : """ Handle to a StoreGateSvc/DetectorStore instance: it will be used to retrieve data during the course of the job """,
    'RegisterForContextService' : """ The flag to enforce the registration for Algorithm Context Service """,
    'RootStreamName' : """ Name of the output ROOT stream (file) that the THistSvc uses """,
    'HistNamePostfix' : """ The postfix for the histogram THx name """,
    'UserStore' : """ Handle to a UserDataSvc/UserDataSvc instance: it will be used to retrieve user data during the course of the job """,
    'HistTitlePostfix' : """ The postfix for the histogram THx title """,
    'EvtStore' : """ Handle to a StoreGateSvc instance: it will be used to retrieve data during the course of the job """,
    'THistSvc' : """ Handle to a THistSvc instance: it will be used to write ROOT objects to ROOT files """,
    'HistNamePrefix' : """ The prefix for the histogram THx name """,
    'DebugEventNumber' : """ Specify a debug event number and when it hits it, will print filename and also go verbose mode for main execute """,
    'RootDirName' : """ Name of the ROOT directory inside the ROOT file where the histograms will go """,
  }
  def __init__(self, name = Configurable.DefaultName, **kwargs):
      super(ZdZdPlottingAlg, self).__init__(name)
      for n,v in kwargs.items():
         setattr(self, n, v)
  def getDlls( self ):
      return 'ZdZdPlotting'
  def getType( self ):
      return 'ZdZdPlottingAlg'
  pass # class ZdZdPlottingAlg
