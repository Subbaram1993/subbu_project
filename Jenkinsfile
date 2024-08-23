pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                env {
                    script {
                        BUILD_TAG = "${JOB_NAME}-${BUILD_NUMBER}"
                        NODE_HOME = '/usr/local/node'
                        PATH = "$NODE_HOME/bin:$PATH"
                    }
                }
                sh 'npm install'
                sh 'npm run build'
                sh 'echo $BUILD_TAG'
            }
        }
    }
}
