﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:4.0.30319.42000
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace LMDBWcf_Client.LMDBServiceReference {
    
    
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    [System.ServiceModel.ServiceContractAttribute(ConfigurationName="LMDBServiceReference.ILMDBService")]
    public interface ILMDBService {
        
        [System.ServiceModel.OperationContractAttribute(Action="http://tempuri.org/ILMDBService/GetData", ReplyAction="http://tempuri.org/ILMDBService/GetDataResponse")]
        string GetData(string dbName, string fileName, byte[] buffer);
        
        [System.ServiceModel.OperationContractAttribute(Action="http://tempuri.org/ILMDBService/GetData", ReplyAction="http://tempuri.org/ILMDBService/GetDataResponse")]
        System.Threading.Tasks.Task<string> GetDataAsync(string dbName, string fileName, byte[] buffer);
    }
    
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    public interface ILMDBServiceChannel : LMDBWcf_Client.LMDBServiceReference.ILMDBService, System.ServiceModel.IClientChannel {
    }
    
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    public partial class LMDBServiceClient : System.ServiceModel.ClientBase<LMDBWcf_Client.LMDBServiceReference.ILMDBService>, LMDBWcf_Client.LMDBServiceReference.ILMDBService {
        
        public LMDBServiceClient() {
        }
        
        public LMDBServiceClient(string endpointConfigurationName) : 
                base(endpointConfigurationName) {
        }
        
        public LMDBServiceClient(string endpointConfigurationName, string remoteAddress) : 
                base(endpointConfigurationName, remoteAddress) {
        }
        
        public LMDBServiceClient(string endpointConfigurationName, System.ServiceModel.EndpointAddress remoteAddress) : 
                base(endpointConfigurationName, remoteAddress) {
        }
        
        public LMDBServiceClient(System.ServiceModel.Channels.Binding binding, System.ServiceModel.EndpointAddress remoteAddress) : 
                base(binding, remoteAddress) {
        }
        
        public string GetData(string dbName, string fileName, byte[] buffer) {
            return base.Channel.GetData(dbName, fileName, buffer);
        }
        
        public System.Threading.Tasks.Task<string> GetDataAsync(string dbName, string fileName, byte[] buffer) {
            return base.Channel.GetDataAsync(dbName, fileName, buffer);
        }
    }
}
